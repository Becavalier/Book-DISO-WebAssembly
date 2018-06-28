__ATPOSTRUN__.push(function() {
	const fileName = '/persistant_data/file.txt';
	FS.mkdir('/persistant_data');
  FS.mount(IDBFS, {}, '/persistant_data');

  // [IDB -> VFS]
  FS.syncfs(true, function (err) {
  	// read file and append new string;
    var stream = FS.open(fileName, 'a+');
		var data = new Uint8Array([65, 66, 67, 68]);
		FS.llseek(stream, 0, 2);
		FS.write(stream, data, 0, data.length);
		FS.close(stream);

		// [VFS -> IDB]
	  FS.syncfs(false, function (err) {
			var buffer = FS.readFile(fileName, {
				encoding: 'binary'
			});
			console.log(Module['intArrayToString'](buffer));
	  });
  });
});





