fetch('main.wasm').then(response => response.arrayBuffer()).then(bytes => {
	const mutexAddr = 0;
	onmessage = function(e) {
    let memory = e.data;
    let imports = {env: {memory: memory}};
    let module = WebAssembly.instantiate(bytes, imports).then(
      ({instance}) => {
          instance.exports.lockMutex(mutexAddr);
          instance.exports.unlockMutex(mutexAddr);
      });
	};
});