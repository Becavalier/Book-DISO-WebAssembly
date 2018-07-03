#include <iostream>
#include <EGL/egl.h>
#include <GLES2/gl2.h>

// Global data.
GLuint userProgramObject;

///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint loadShader (GLenum type, const char *shaderSrc) {
   GLuint shader;
   GLint compiled;

   // Create the shader object.
   shader = glCreateShader (type);

   if (shader == 0)
    return 0;

   // Load the shader source.
   glShaderSource (shader, 1, &shaderSrc, NULL);

   // Compile the shader.
   glCompileShader (shader);

   // Check the compile status.
   glGetShaderiv (shader, GL_COMPILE_STATUS, &compiled);

   if (!compiled) {
      GLint infoLen = 0;
      glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &infoLen);
      glDeleteShader (shader);
      return 0;
   }

   return shader;
}

///
// Initialize the shader and program object.
//
int initialize_stage () {
   char vShaderStr[] =
      "attribute vec4 vPosition;    \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = vPosition;  \n"
      "}                            \n";

   char fShaderStr[] =
      "precision mediump float;\n"\
      "void main()                                  \n"
      "{                                            \n"
      "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
      "}                                            \n";

   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint linked;

   // Load the vertex/fragment shaders.
   vertexShader = loadShader (GL_VERTEX_SHADER, vShaderStr);
   fragmentShader = loadShader (GL_FRAGMENT_SHADER, fShaderStr);

   // Create the program object.
   programObject = glCreateProgram();

   if (programObject == 0)
      return 0;

   glAttachShader(programObject, vertexShader);
   glAttachShader(programObject, fragmentShader);

   // Bind vPosition to attribute 0.
   glBindAttribLocation(programObject, 0, "vPosition");

   // Link the program.
   glLinkProgram(programObject);

   // Check the link status.
   glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

   if (!linked) {
      GLint infoLen = 0;

      glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

      glDeleteProgram(programObject);
      return GL_FALSE;
   }

   // Store the program object.
   userProgramObject = programObject;

   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   return GL_TRUE;
}

///
// Draw a triangle using the shader pair created in initialize_stage()
//
void draw (int winWidth, int winHeight) {
   GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f,
                           -0.5f, -0.5f, 0.0f,
                            0.5f, -0.5f, 0.0f };

   // No clientside arrays, so do this in a webgl-friendly manner.
   GLuint vertexPosObject;
   glGenBuffers(1, &vertexPosObject);
   glBindBuffer(GL_ARRAY_BUFFER, vertexPosObject);
   glBufferData(GL_ARRAY_BUFFER, 9*4, vVertices, GL_STATIC_DRAW);

   // Set the viewport.
   glViewport (0, 0, winWidth, winHeight);

   // Clear the color buffer.
   glClear (GL_COLOR_BUFFER_BIT);

   // Use the program object.
   glUseProgram (userProgramObject);

   // Load the vertex data.
   glBindBuffer(GL_ARRAY_BUFFER, vertexPosObject);
   glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, 0);
   glEnableVertexAttribArray(0);

   glDrawArrays ( GL_TRIANGLES, 0, 3 );
}


int main(int argc, char *argv[]) {
    // EGL related...
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    EGLint major, minor;
    eglInitialize(display, &major, &minor);

    eglBindAPI(EGL_OPENGL_ES_API);

    EGLint numConfigs;
    eglGetConfigs(display, NULL, 0, &numConfigs);

    EGLint attribs[] = {
        EGL_RED_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_BLUE_SIZE, 5,
        EGL_NONE
    };
    EGLConfig config;
    eglChooseConfig(display, attribs, &config, 1, &numConfigs);

    EGLNativeWindowType window;
    EGLint surfaceAttributes[] = { EGL_NONE };
    EGLSurface surface = eglCreateWindowSurface(display, config, window, surfaceAttributes);

    EGLint width, height;
    eglQuerySurface(display, surface, EGL_WIDTH, &width);
    eglQuerySurface(display, surface, EGL_HEIGHT, &height);

    // OpenGL related...
    EGLint contextAttributes[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
    EGLContext context = eglCreateContext(display, config, NULL, contextAttributes);

    eglMakeCurrent(display, surface, surface, context);

    // Init OpenGL.
    initialize_stage();
    // Drawing picture.
    draw(width, height);
    eglSwapBuffers(display, surface);

    return 0;
}
