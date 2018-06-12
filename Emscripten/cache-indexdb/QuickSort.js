var c;c||(c=typeof Module !== 'undefined' ? Module : {});var aa=performance.now(),k={},q;for(q in c)c.hasOwnProperty(q)&&(k[q]=c[q]);c.arguments=[];c.thisProgram="./this.program";c.quit=function(a,b){throw b;};c.preRun=[];c.postRun=[];var r=!1,t=!1,u=!1,ba=!1;
if(c.ENVIRONMENT)if("WEB"===c.ENVIRONMENT)r=!0;else if("WORKER"===c.ENVIRONMENT)t=!0;else if("NODE"===c.ENVIRONMENT)u=!0;else if("SHELL"===c.ENVIRONMENT)ba=!0;else throw Error("Module['ENVIRONMENT'] value is not valid. must be one of: WEB|WORKER|NODE|SHELL.");else r="object"===typeof window,t="function"===typeof importScripts,u="object"===typeof process&&"function"===typeof require&&!r&&!t,ba=!r&&!u&&!t;
if(u){var ca,da;c.read=function(a,b){ca||(ca=require("fs"));da||(da=require("path"));a=da.normalize(a);a=ca.readFileSync(a);return b?a:a.toString()};c.readBinary=function(a){a=c.read(a,!0);a.buffer||(a=new Uint8Array(a));assert(a.buffer);return a};1<process.argv.length&&(c.thisProgram=process.argv[1].replace(/\\/g,"/"));c.arguments=process.argv.slice(2);"undefined"!==typeof module&&(module.exports=c);process.on("uncaughtException",function(a){if(!(a instanceof v))throw a;});process.on("unhandledRejection",
function(){process.exit(1)});c.inspect=function(){return"[Emscripten Module object]"}}else if(ba)"undefined"!=typeof read&&(c.read=function(a){return read(a)}),c.readBinary=function(a){if("function"===typeof readbuffer)return new Uint8Array(readbuffer(a));a=read(a,"binary");assert("object"===typeof a);return a},"undefined"!=typeof scriptArgs?c.arguments=scriptArgs:"undefined"!=typeof arguments&&(c.arguments=arguments),"function"===typeof quit&&(c.quit=function(a){quit(a)});else if(r||t)c.read=function(a){var b=
new XMLHttpRequest;b.open("GET",a,!1);b.send(null);return b.responseText},t&&(c.readBinary=function(a){var b=new XMLHttpRequest;b.open("GET",a,!1);b.responseType="arraybuffer";b.send(null);return new Uint8Array(b.response)}),c.readAsync=function(a,b,e){var d=new XMLHttpRequest;d.open("GET",a,!0);d.responseType="arraybuffer";d.onload=function(){200==d.status||0==d.status&&d.response?b(d.response):e()};d.onerror=e;d.send(null)},c.setWindowTitle=function(a){document.title=a};
c.print="undefined"!==typeof console?console.log.bind(console):"undefined"!==typeof print?print:null;c.printErr="undefined"!==typeof printErr?printErr:"undefined"!==typeof console&&console.warn.bind(console)||c.print;c.print=c.print;c.printErr=c.printErr;for(q in k)k.hasOwnProperty(q)&&(c[q]=k[q]);k=void 0;function ea(a){assert(!fa);var b=w;w=w+a+15&-16;return b}function ha(a){var b;b||(b=16);return Math.ceil(a/b)*b}var ia=0;function assert(a,b){a||x("Assertion failed: "+b)}
function ja(a){var b=c["_"+a];assert(b,"Cannot call unknown function "+a+", make sure it is exported");return b}var oa={stackSave:function(){ka()},stackRestore:function(){la()},arrayToC:function(a){var b=ma(a.length);z.set(a,b);return b},stringToC:function(a){var b=0;if(null!==a&&void 0!==a&&0!==a){var e=(a.length<<2)+1;b=ma(e);na(a,A,b,e)}return b}},pa={string:oa.stringToC,array:oa.arrayToC},qa,ra;["1","QuickSort"].forEach(function(a){!qa&&/^\d+$/.test(a)?qa=Number(a):ra=a});
function sa(a){var b=ra;function e(a){return new Promise(function(d,e){var f=a.transaction(["$$_wasm_module_instances"]).objectStore("$$_wasm_module_instances").get(b);f.onerror=e.bind(null,"Error getting wasm module"+b);f.onsuccess=function(){f.result?d(f.result):e("Module was not found in wasm cache for: "+b)}})}function d(a,d){a=a.transaction(["$$_wasm_module_instances"],"readwrite").objectStore("$$_wasm_module_instances");try{var e=a.put(d,b);e.onsuccess=function(){console.log("New record stored in wasm cache: "+
b)}}catch(l){console.warn("Failed to store in wasm cache: "+l)}}if(indexedDB)return function(){return new Promise(function(a,b){var d=indexedDB.open("$emscripten-cache",qa);d.onerror=b.bind(null,"Error opening wasm cache database.");d.onsuccess=function(){a(d.result)};d.onupgradeneeded=function(a){var b=d.result;b.objectStoreNames.contains("$$_wasm_module_instances")&&(console.log("Clearing out module cache at version: "+a.oldVersion),b.deleteObjectStore("$$_wasm_module_instances"));console.log("Creating wasm cache at version: "+
a.newVersion);b.createObjectStore("$$_wasm_module_instances")}})}().then(function(g){if(a)"[object WebAssembly.Module]"===Object.prototype.toString.call(a)&&d(g,a);else return e(g).then(function(a){console.log("Found module in wasm cache: "+b);return a},function(a){console.error(a);return!1})});c.printErr("Warning: Your current environment does not support IndexedDB!")}
function B(a){var b;if(0===b||!a)return"";for(var e=0,d,g=0;;){d=A[a+g>>0];e|=d;if(0==d&&!b)break;g++;if(b&&g==b)break}b||(b=g);d="";if(128>e){for(;0<b;)e=String.fromCharCode.apply(String,A.subarray(a,a+Math.min(b,1024))),d=d?d+e:e,a+=1024,b-=1024;return d}return ta(A,a)}var ua="undefined"!==typeof TextDecoder?new TextDecoder("utf8"):void 0;
function ta(a,b){for(var e=b;a[e];)++e;if(16<e-b&&a.subarray&&ua)return ua.decode(a.subarray(b,e));for(e="";;){var d=a[b++];if(!d)return e;if(d&128){var g=a[b++]&63;if(192==(d&224))e+=String.fromCharCode((d&31)<<6|g);else{var f=a[b++]&63;if(224==(d&240))d=(d&15)<<12|g<<6|f;else{var h=a[b++]&63;if(240==(d&248))d=(d&7)<<18|g<<12|f<<6|h;else{var l=a[b++]&63;if(248==(d&252))d=(d&3)<<24|g<<18|f<<12|h<<6|l;else{var p=a[b++]&63;d=(d&1)<<30|g<<24|f<<18|h<<12|l<<6|p}}}65536>d?e+=String.fromCharCode(d):(d-=
65536,e+=String.fromCharCode(55296|d>>10,56320|d&1023))}}else e+=String.fromCharCode(d)}}
function na(a,b,e,d){if(0<d){d=e+d-1;for(var g=0;g<a.length;++g){var f=a.charCodeAt(g);55296<=f&&57343>=f&&(f=65536+((f&1023)<<10)|a.charCodeAt(++g)&1023);if(127>=f){if(e>=d)break;b[e++]=f}else{if(2047>=f){if(e+1>=d)break;b[e++]=192|f>>6}else{if(65535>=f){if(e+2>=d)break;b[e++]=224|f>>12}else{if(2097151>=f){if(e+3>=d)break;b[e++]=240|f>>18}else{if(67108863>=f){if(e+4>=d)break;b[e++]=248|f>>24}else{if(e+5>=d)break;b[e++]=252|f>>30;b[e++]=128|f>>24&63}b[e++]=128|f>>18&63}b[e++]=128|f>>12&63}b[e++]=
128|f>>6&63}b[e++]=128|f&63}}b[e]=0}}function va(a){for(var b=0,e=0;e<a.length;++e){var d=a.charCodeAt(e);55296<=d&&57343>=d&&(d=65536+((d&1023)<<10)|a.charCodeAt(++e)&1023);127>=d?++b:b=2047>=d?b+2:65535>=d?b+3:2097151>=d?b+4:67108863>=d?b+5:b+6}return b}"undefined"!==typeof TextDecoder&&new TextDecoder("utf-16le");var buffer,z,A,wa,C,xa,ya;
function za(){c.HEAP8=z=new Int8Array(buffer);c.HEAP16=wa=new Int16Array(buffer);c.HEAP32=C=new Int32Array(buffer);c.HEAPU8=A=new Uint8Array(buffer);c.HEAPU16=new Uint16Array(buffer);c.HEAPU32=new Uint32Array(buffer);c.HEAPF32=xa=new Float32Array(buffer);c.HEAPF64=ya=new Float64Array(buffer)}var D,w,fa,Aa,E,Ba,Ca,F;D=w=Aa=E=Ba=Ca=F=0;fa=!1;
function Da(){x("Cannot enlarge memory arrays. Either (1) compile with  -s TOTAL_MEMORY=X  with X higher than the current value "+G+", (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which allows increasing the size at runtime, or (3) if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0 ")}var Ea=c.TOTAL_STACK||5242880,G=c.TOTAL_MEMORY||16777216;G<Ea&&c.printErr("TOTAL_MEMORY should be larger than TOTAL_STACK, was "+G+"! (TOTAL_STACK="+Ea+")");
c.buffer?buffer=c.buffer:("object"===typeof WebAssembly&&"function"===typeof WebAssembly.Memory?(c.wasmMemory=new WebAssembly.Memory({initial:G/65536,maximum:G/65536}),buffer=c.wasmMemory.buffer):buffer=new ArrayBuffer(G),c.buffer=buffer);za();C[0]=1668509029;wa[1]=25459;if(115!==A[2]||99!==A[3])throw"Runtime error: expected the system to be little-endian!";
function H(a){for(;0<a.length;){var b=a.shift();if("function"==typeof b)b();else{var e=b.m;"number"===typeof e?void 0===b.l?c.dynCall_v(e):c.dynCall_vi(e,b.l):e(void 0===b.l?null:b.l)}}}var Fa=[],Ga=[],Ha=[],Ia=[],Ja=[],Ka=!1;function La(){var a=c.preRun.shift();Fa.unshift(a)}var I=0,Ma=null,J=null;c.preloadedImages={};c.preloadedAudios={};function K(a){return String.prototype.startsWith?a.startsWith("data:application/octet-stream;base64,"):0===a.indexOf("data:application/octet-stream;base64,")}
(function(){function a(){try{if(c.wasmBinary)return new Uint8Array(c.wasmBinary);if(c.readBinary)return c.readBinary(g);throw"on the web, we need the wasm binary to be preloaded and set on Module['wasmBinary']. emcc.py will do that for you when generating HTML (but not JS)";}catch(m){x(m)}}function b(){return c.wasmBinary||!r&&!t||"function"!==typeof fetch?new Promise(function(b){b(a())}):fetch(g,{credentials:"same-origin"}).then(function(a){if(!a.ok)throw"failed to load wasm binary file at '"+g+
"'";return a.arrayBuffer()}).catch(function(){return a()})}function e(a){function d(a){l=a.exports;if(l.memory){a=l.memory;var b=c.buffer;a.byteLength<b.byteLength&&c.printErr("the new buffer in mergeMemory is smaller than the previous one. in native wasm, we should grow memory here");b=new Int8Array(b);(new Int8Array(a)).set(b);c.buffer=buffer=a;za()}c.asm=l;c.usingWasm=!0;I--;c.monitorRunDependencies&&c.monitorRunDependencies(I);0==I&&(null!==Ma&&(clearInterval(Ma),Ma=null),J&&(a=J,J=null,a()))}
function e(a){d(a.instance)}function y(a){b().then(function(a){return WebAssembly.instantiate(a,h)}).then(a).catch(function(a){c.printErr("failed to asynchronously prepare wasm: "+a);x(a)})}if("object"!==typeof WebAssembly)return c.printErr("no native wasm support detected"),!1;if(!(c.wasmMemory instanceof WebAssembly.Memory))return c.printErr("no native wasm Memory in use"),!1;a.memory=c.wasmMemory;h.global={NaN:NaN,Infinity:Infinity};h["global.Math"]=Math;h.env=a;I++;c.monitorRunDependencies&&c.monitorRunDependencies(I);
if(c.instantiateWasm)try{return c.instantiateWasm(h,d)}catch(bb){return c.printErr("Module.instantiateWasm callback failed with error: "+bb),!1}sa().then(function(a){a?WebAssembly.instantiate(a,h).then(function(b){e({instance:b,module:a})}):c.wasmBinary||"function"!==typeof WebAssembly.instantiateStreaming||K(g)||"function"!==typeof fetch?y(e):WebAssembly.instantiateStreaming(fetch(g,{credentials:"same-origin"}),h).then(function(a){e(a);sa(a.module)}).catch(function(a){c.printErr("wasm streaming compile failed: "+
a);c.printErr("falling back to ArrayBuffer instantiation");y(e)})});return{}}var d="QuickSort.wast",g="QuickSort.wasm",f="QuickSort.temp.asm.js";"function"===typeof c.locateFile&&(K(d)||(d=c.locateFile(d)),K(g)||(g=c.locateFile(g)),K(f)||(f=c.locateFile(f)));var h={global:null,env:null,asm2wasm:{"f64-rem":function(a,b){return a%b},"debugger":function(){debugger}},parent:c},l=null;c.asmPreload=c.asm;var p=c.reallocBuffer;c.reallocBuffer=function(a){if("asmjs"===n)var b=p(a);else a:{var d=c.usingWasm?
65536:16777216;0<a%d&&(a+=d-a%d);d=c.buffer.byteLength;if(c.usingWasm)try{b=-1!==c.wasmMemory.grow((a-d)/65536)?c.buffer=c.wasmMemory.buffer:null;break a}catch(y){b=null;break a}b=void 0}return b};var n="";c.asm=function(a,b){if(!b.table){a=c.wasmTableSize;void 0===a&&(a=1024);var d=c.wasmMaxTableSize;b.table="object"===typeof WebAssembly&&"function"===typeof WebAssembly.Table?void 0!==d?new WebAssembly.Table({initial:a,maximum:d,element:"anyfunc"}):new WebAssembly.Table({initial:a,element:"anyfunc"}):
Array(a);c.wasmTable=b.table}b.memoryBase||(b.memoryBase=c.STATIC_BASE);b.tableBase||(b.tableBase=0);(b=e(b))||x("no binaryen method succeeded. consider enabling more options, like interpreting, if you want that: https://github.com/kripken/emscripten/wiki/WebAssembly#binaryen-methods");return b}})();D=1024;w=D+22624;Ga.push({m:function(){Oa()}},{m:function(){Pa()}});c.STATIC_BASE=D;c.STATIC_BUMP=22624;w+=16;function Qa(){return!!Qa.c}
function Ra(a){c.___errno_location&&(C[c.___errno_location()>>2]=a);return a}var L=0;function M(){L+=4;return C[L-4>>2]}var O={};function P(a,b){L=b;try{var e=M(),d=M(),g=M();a=0;P.c||(P.c=[null,[],[]],P.w=function(a,b){var d=P.c[a];assert(d);0===b||10===b?((1===a?c.print:c.printErr)(ta(d,0)),d.length=0):d.push(b)});for(b=0;b<g;b++){for(var f=C[d+8*b>>2],h=C[d+(8*b+4)>>2],l=0;l<h;l++)P.w(e,A[f+l]);a+=h}return a}catch(p){return"undefined"!==typeof FS&&p instanceof FS.g||x(p),-p.h}}var Sa=w;w+=16;
var Ta,Q={};function R(a){if(0===a)return 0;a=B(a);if(!Q.hasOwnProperty(a))return 0;R.c&&Ua(R.c);a=Q[a];var b=va(a)+1,e=Va(b);e&&na(a,z,e,b);R.c=e;return R.c}function S(a){return 0===a%4&&(0!==a%100||0===a%400)}function Wa(a,b){for(var e=0,d=0;d<=b;e+=a[d++]);return e}var T=[31,29,31,30,31,30,31,31,30,31,30,31],U=[31,28,31,30,31,30,31,31,30,31,30,31];
function V(a,b){for(a=new Date(a.getTime());0<b;){var e=a.getMonth(),d=(S(a.getFullYear())?T:U)[e];if(b>d-a.getDate())b-=d-a.getDate()+1,a.setDate(1),11>e?a.setMonth(e+1):(a.setMonth(0),a.setFullYear(a.getFullYear()+1));else{a.setDate(a.getDate()+b);break}}return a}
function Xa(a,b,e,d){function g(a,b,d){for(a="number"===typeof a?a.toString():a||"";a.length<b;)a=d[0]+a;return a}function f(a,b){return g(a,b,"0")}function h(a,b){function d(a){return 0>a?-1:0<a?1:0}var y;0===(y=d(a.getFullYear()-b.getFullYear()))&&0===(y=d(a.getMonth()-b.getMonth()))&&(y=d(a.getDate()-b.getDate()));return y}function l(a){switch(a.getDay()){case 0:return new Date(a.getFullYear()-1,11,29);case 1:return a;case 2:return new Date(a.getFullYear(),0,3);case 3:return new Date(a.getFullYear(),
0,2);case 4:return new Date(a.getFullYear(),0,1);case 5:return new Date(a.getFullYear()-1,11,31);case 6:return new Date(a.getFullYear()-1,11,30)}}function p(a){a=V(new Date(a.a+1900,0,1),a.j);var b=l(new Date(a.getFullYear()+1,0,4));return 0>=h(l(new Date(a.getFullYear(),0,4)),a)?0>=h(b,a)?a.getFullYear()+1:a.getFullYear():a.getFullYear()-1}var n=C[d+40>>2];d={F:C[d>>2],D:C[d+4>>2],i:C[d+8>>2],f:C[d+12>>2],b:C[d+16>>2],a:C[d+20>>2],s:C[d+24>>2],j:C[d+28>>2],P:C[d+32>>2],C:C[d+36>>2],G:n?B(n):""};
e=B(e);n={"%c":"%a %b %d %H:%M:%S %Y","%D":"%m/%d/%y","%F":"%Y-%m-%d","%h":"%b","%r":"%I:%M:%S %p","%R":"%H:%M","%T":"%H:%M:%S","%x":"%m/%d/%y","%X":"%H:%M:%S"};for(var m in n)e=e.replace(new RegExp(m,"g"),n[m]);var N="Sunday Monday Tuesday Wednesday Thursday Friday Saturday".split(" "),Na="January February March April May June July August September October November December".split(" ");n={"%a":function(a){return N[a.s].substring(0,3)},"%A":function(a){return N[a.s]},"%b":function(a){return Na[a.b].substring(0,
3)},"%B":function(a){return Na[a.b]},"%C":function(a){return f((a.a+1900)/100|0,2)},"%d":function(a){return f(a.f,2)},"%e":function(a){return g(a.f,2," ")},"%g":function(a){return p(a).toString().substring(2)},"%G":function(a){return p(a)},"%H":function(a){return f(a.i,2)},"%I":function(a){a=a.i;0==a?a=12:12<a&&(a-=12);return f(a,2)},"%j":function(a){return f(a.f+Wa(S(a.a+1900)?T:U,a.b-1),3)},"%m":function(a){return f(a.b+1,2)},"%M":function(a){return f(a.D,2)},"%n":function(){return"\n"},"%p":function(a){return 0<=
a.i&&12>a.i?"AM":"PM"},"%S":function(a){return f(a.F,2)},"%t":function(){return"\t"},"%u":function(a){return(new Date(a.a+1900,a.b+1,a.f,0,0,0,0)).getDay()||7},"%U":function(a){var b=new Date(a.a+1900,0,1),d=0===b.getDay()?b:V(b,7-b.getDay());a=new Date(a.a+1900,a.b,a.f);return 0>h(d,a)?f(Math.ceil((31-d.getDate()+(Wa(S(a.getFullYear())?T:U,a.getMonth()-1)-31)+a.getDate())/7),2):0===h(d,b)?"01":"00"},"%V":function(a){var b=l(new Date(a.a+1900,0,4)),d=l(new Date(a.a+1901,0,4)),e=V(new Date(a.a+1900,
0,1),a.j);return 0>h(e,b)?"53":0>=h(d,e)?"01":f(Math.ceil((b.getFullYear()<a.a+1900?a.j+32-b.getDate():a.j+1-b.getDate())/7),2)},"%w":function(a){return(new Date(a.a+1900,a.b+1,a.f,0,0,0,0)).getDay()},"%W":function(a){var b=new Date(a.a,0,1),d=1===b.getDay()?b:V(b,0===b.getDay()?1:7-b.getDay()+1);a=new Date(a.a+1900,a.b,a.f);return 0>h(d,a)?f(Math.ceil((31-d.getDate()+(Wa(S(a.getFullYear())?T:U,a.getMonth()-1)-31)+a.getDate())/7),2):0===h(d,b)?"01":"00"},"%y":function(a){return(a.a+1900).toString().substring(2)},
"%Y":function(a){return a.a+1900},"%z":function(a){a=a.C;var b=0<=a;a=Math.abs(a)/60;return(b?"+":"-")+String("0000"+(a/60*100+a%60)).slice(-4)},"%Z":function(a){return a.G},"%%":function(){return"%"}};for(m in n)0<=e.indexOf(m)&&(e=e.replace(new RegExp(m,"g"),n[m](d)));m=Ya(e);if(m.length>b)return 0;z.set(m,a);return m.length-1}var W,X;
Ta?(X=C[Sa>>2],W=C[X>>2]):(Ta=!0,Q.USER=Q.LOGNAME="web_user",Q.PATH="/",Q.PWD="/",Q.HOME="/home/web_user",Q.LANG="C.UTF-8",Q._=c.thisProgram,W=ea(1024),X=ea(256),C[X>>2]=W,C[Sa>>2]=X);var Y=[],Za=0,Z;for(Z in Q)if("string"===typeof Q[Z]){var $a=Z+"="+Q[Z];Y.push($a);Za+=$a.length}if(1024<Za)throw Error("Environment size exceeded TOTAL_ENV_SIZE!");for(var ab=0;ab<Y.length;ab++){for(var cb=$a=Y[ab],db=W,eb=0;eb<cb.length;++eb)z[db++>>0]=cb.charCodeAt(eb);z[db>>0]=0;C[X+4*ab>>2]=W;W+=$a.length+1}
C[X+4*Y.length>>2]=0;F=ea(4);Aa=E=ha(w);Ba=Aa+Ea;Ca=ha(Ba);C[F>>2]=Ca;fa=!0;function Ya(a){var b=Array(va(a)+1);na(a,b,0,b.length);return b}c.wasmTableSize=478;c.wasmMaxTableSize=478;c.u={};
c.v={abort:x,enlargeMemory:function(){Da()},getTotalMemory:function(){return G},abortOnCannotGrowMemory:Da,__ZSt18uncaught_exceptionv:Qa,___lock:function(){},___map_file:function(){Ra(1);return-1},___setErrNo:Ra,___syscall140:function(a,b){L=b;try{var e=O.o();M();var d=M(),g=M(),f=M();FS.M(e,d,f);C[g>>2]=e.position;e.A&&0===d&&0===f&&(e.A=null);return 0}catch(h){return"undefined"!==typeof FS&&h instanceof FS.g||x(h),-h.h}},___syscall145:function(a,b){L=b;try{var e=O.o(),d=M(),g=M();return O.J(e,d,
g)}catch(f){return"undefined"!==typeof FS&&f instanceof FS.g||x(f),-f.h}},___syscall146:P,___syscall54:function(a,b){L=b;return 0},___syscall6:function(a,b){L=b;try{var e=O.o();FS.close(e);return 0}catch(d){return"undefined"!==typeof FS&&d instanceof FS.g||x(d),-d.h}},___syscall91:function(a,b){L=b;try{var e=M(),d=M(),g=O.B[e];if(!g)return 0;if(d===g.L){var f=FS.K(g.fd);O.I(e,f,d,g.flags);FS.O(f);O.B[e]=null;g.H&&Ua(g.N)}return 0}catch(h){return"undefined"!==typeof FS&&h instanceof FS.g||x(h),-h.h}},
___unlock:function(){},_abort:function(){c.abort()},_emscripten_memcpy_big:function(a,b,e){A.set(A.subarray(b,b+e),a);return a},_getenv:R,_pthread_cond_wait:function(){return 0},_strftime_l:function(a,b,e,d){return Xa(a,b,e,d)},DYNAMICTOP_PTR:F,STACKTOP:E};var fb=c.asm(c.u,c.v,buffer);c.asm=fb;
var Oa=c.__GLOBAL__I_000101=function(){return c.asm.__GLOBAL__I_000101.apply(null,arguments)},Pa=c.__GLOBAL__sub_I_iostream_cpp=function(){return c.asm.__GLOBAL__sub_I_iostream_cpp.apply(null,arguments)},Ua=c._free=function(){return c.asm._free.apply(null,arguments)},Va=c._malloc=function(){return c.asm._malloc.apply(null,arguments)};c._quickSort=function(){return c.asm._quickSort.apply(null,arguments)};
var ma=c.stackAlloc=function(){return c.asm.stackAlloc.apply(null,arguments)},la=c.stackRestore=function(){return c.asm.stackRestore.apply(null,arguments)},ka=c.stackSave=function(){return c.asm.stackSave.apply(null,arguments)};c.dynCall_v=function(){return c.asm.dynCall_v.apply(null,arguments)};c.dynCall_vi=function(){return c.asm.dynCall_vi.apply(null,arguments)};c.asm=fb;
c.cwrap=function(a,b,e){e=e||[];var d=ja(a),g=e.every(function(a){return"number"===a});return"string"!==b&&g?d:function(){var d=e,g=arguments,l=ja(a),p=[],n=0;if(g)for(var m=0;m<g.length;m++){var N=pa[d[m]];N?(0===n&&(n=ka()),p[m]=N(g[m])):p[m]=g[m]}d=l.apply(null,p);"string"===b?d=B(d):"boolean"===b&&(d=!!d);0!==n&&la(n);return d}};
c.getValue=function(a,b){b=b||"i8";"*"===b.charAt(b.length-1)&&(b="i32");switch(b){case "i1":return z[a>>0];case "i8":return z[a>>0];case "i16":return wa[a>>1];case "i32":return C[a>>2];case "i64":return C[a>>2];case "float":return xa[a>>2];case "double":return ya[a>>3];default:x("invalid type for getValue: "+b)}return null};function v(a){this.name="ExitStatus";this.message="Program terminated with exit("+a+")";this.status=a}v.prototype=Error();v.prototype.constructor=v;
J=function gb(){c.calledRun||hb();c.calledRun||(J=gb)};
function hb(){function a(){if(!c.calledRun&&(c.calledRun=!0,!ia)){Ka||(Ka=!0,H(Ga));H(Ha);if(c.onRuntimeInitialized)c.onRuntimeInitialized();if(c.postRun)for("function"==typeof c.postRun&&(c.postRun=[c.postRun]);c.postRun.length;){var a=c.postRun.shift();Ja.unshift(a)}H(Ja)}}if(!(0<I)){if(c.preRun)for("function"==typeof c.preRun&&(c.preRun=[c.preRun]);c.preRun.length;)La();H(Fa);0<I||c.calledRun||(c.setStatus?(c.setStatus("Running..."),setTimeout(function(){setTimeout(function(){c.setStatus("")},1);
a()},1)):a())}}c.run=hb;c.exit=function(a,b){if(!b||!c.noExitRuntime||0!==a){if(!c.noExitRuntime&&(ia=!0,E=void 0,H(Ia),c.onExit))c.onExit(a);u&&process.exit(a);c.quit(a,new v(a))}};function x(a){if(c.onAbort)c.onAbort(a);void 0!==a?(c.print(a),c.printErr(a),a=JSON.stringify(a)):a="";ia=!0;throw"abort("+a+"). Build with -s ASSERTIONS=1 for more info.";}c.abort=x;if(c.preInit)for("function"==typeof c.preInit&&(c.preInit=[c.preInit]);0<c.preInit.length;)c.preInit.pop()();c.noExitRuntime=!0;hb();
Ja.push(function(){for(var a=[11,24,36,42,4,25,9,1,0],b=c.cwrap("quickSort","number",["array","number","number"])(a,0,a.length-1),e=[],d=0;d<a.length;d++)e.push(c.getValue(b+d,"i8"));console.log(e);b=performance.timing;a=b.loadEventStart-b.navigationStart;b=(new Date).getTime()-b.navigationStart;console.log("Application ET: ",Math.round(performance.now()-aa),"ms");console.log("Application LT: ",a,"ms");console.log("Application TT: ",b,"ms")});
