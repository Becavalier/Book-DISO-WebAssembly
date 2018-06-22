__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	var _t_ptr = Module['getPointer'](_t);
	var __class__ = _t['__class__'];

	console.log(_t_ptr);
	console.log(Module['wrapPointer'](_t_ptr, __class__)['getValueXByValue']());

	console.log(_t['returnNull']());

	var voidPrtObj = _t['returnVoidPtr'](_t);
	var voidPrtNum = _t['returnAnyPtr'](_t);

	console.log(Module['castObject'](voidPrtObj, __class__));
	console.log(Module['wrapPointer'](voidPrtNum, __class__));
	Module.destroy(_t);
});
