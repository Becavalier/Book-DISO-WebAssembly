__ATPOSTRUN__.push(() => {
	var _t = new WebIDL(10);
	var _k = new WebIDL(11);
	var _u = new WebIDL(12);
	console.log(_t.getValueXByValue());
	console.log(_t.passThroughByPointer(_k).getValueXByValue());
	console.log(_t.passThroughByReference(_u).getValueXByValue());
	console.log(_t.passThroughToValue(_u).getValueXByValue());
	Module.destroy(_t);
});
