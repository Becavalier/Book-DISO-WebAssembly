__ATPOSTRUN__.push(() => {
	console.log(Module['enum_val1']);
	console.log(Module['enum_val2']);

	console.log(Module['ns_enum_val1']);
	console.log(Module['ns_enum_val2']);

	console.log(Module['xClass']['c_enum_val1']);
	console.log(Module['xClass']['c_enum_val2']);
});
