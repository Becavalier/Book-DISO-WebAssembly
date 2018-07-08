const fs = require("fs");
module.exports = new WebAssembly.Instance(new WebAssembly.Module(fs.readFileSync(__dirname + "/module.optimized.wasm"), {})).exports;