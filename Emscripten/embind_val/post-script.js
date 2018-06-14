__ATPOSTRUN__.push(() => {
  console.log(Module.getDefaultStrValue());
  console.log(Module.getDefaultIntValue());
  Module.manipulateDOM("This is from C++!");
  Module.mountTime();
  console.log(Module['currentTimestamp']);
});
