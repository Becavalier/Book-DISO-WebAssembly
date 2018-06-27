__ATPOSTRUN__.push(function() {
	// make a virtual device;
  var fDevice = FS.makedev(2, 1);


  // register device;
  FS.registerDevice(fDevice, {
    open: function (stream) {
  		console.log("[Open] 'DoublingDevice' device stream.");    
    },
    close: function (stream) {
    	console.log("[Close] 'DoublingDevice' device stream.");
    },
    read: function (stream, buffer, offset, length, position) {
    	console.log("[Read] from 'DoublingDevice' device stream.");
    },
    write: function (stream, buffer, offset, length, position) {
    	// doubling a buffer and return;
      return buffer.map(item => {
        return 2 * item;
      })
    }
  });

  // mount device;
	FS.mkdev('/DoublingDevice', 0777, fDevice);

  // open a device stream;
	var fStream = FS.open('/DoublingDevice', 'w+');

  // write to device stream;
  var data = new Uint32Array(4);
	var _t = FS.write(fStream, new Int32Array([1, 2, 3, 4]), 0, 4, 0);
  console.log(_t);

  // close device stream;
  FS.close(fStream);
});



