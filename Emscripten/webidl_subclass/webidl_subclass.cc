class xClass {
public:
  virtual int virtualFunc (int x) = 0;
  int runVirtualFunc(xClass *self, int x) { 
    return self->virtualFunc(x); 
  }
};