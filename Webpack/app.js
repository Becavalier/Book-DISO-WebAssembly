require.ensure([], function(require) {
	let _WASM_MODULE = require('./module.wasm');
  console.log(_WASM_MODULE['_add'](1, 2));
});

