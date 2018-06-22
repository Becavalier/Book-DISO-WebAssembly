__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10, 20);
	console.log(_t.getValueXByValue());
	console.log(_t.passThroughByReference(_t).getValueXByValue());
	console.log(_t);
	console.log(_t.passThroughByReference(_t));
	Module.destroy(_t);
});
