var http = require('http');
var url = require('url');
var fs = require('fs');
var path =require('path');

const PORT = 8888;

var mime = {
	"html": "text/html;charset=UTF-8",
	"wasm": "application/wasm"
};

http.createServer((request, response) => {
  var realPath = path.join(__dirname, `.${url.parse(request.url).pathname}`);
  fs.access(realPath, fs.constants.R_OK, err => {
    if (err) {
      response.writeHead(404, {
        'Content-Type': 'text/plain'
      });
      response.end();
    } else {
      fs.readFile(realPath, "binary", (err, file) => {
        if (err) {
          response.writeHead(500, {
            'Content-Type': 'text/plain'
          });
          response.end(err.code);
        } else {
        	var ext = path.extname(realPath);
          ext = ext ? ext.slice(1) : 'unknown';
          var contentType = mime[ext] || "text/plain";
          response.writeHead(200, {
            'Content-Type': contentType
          });

          response.write(file, "binary");
          response.end();
        }
      });
    }
  });
}).listen(PORT);
console.log("Server is runing at port: " + PORT + ".")