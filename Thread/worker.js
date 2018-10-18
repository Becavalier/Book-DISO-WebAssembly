const mutexAddr = 0;
onmessage = function(e) {
    let memory = e.data.memory;
    let imports = {env: {memory: memory}};
    WebAssembly.instantiate(e.data.moduleBuffer, imports).then(({instance}) => {
        instance.exports.lockMutex(mutexAddr);
        console.log("worker thread!");
        instance.exports.unlockMutex(mutexAddr);
    });
};
