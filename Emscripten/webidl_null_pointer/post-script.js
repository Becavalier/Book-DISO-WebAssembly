__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	var _ptr = _t['returnNullPtr']();
	console.log(_ptr);
	
	Module.destroy(_t);
});
