__ATPOSTRUN__.push(function(){
	var newFuncPtr = Module.addFunction(function(num) {
	  console.log(`Hello ${num} from JS!`);
  }, "vi");
	Module.asm['_wrapper'](newFuncPtr);
});
