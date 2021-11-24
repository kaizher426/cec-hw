let port, reader, writer;

async function setup() {
	createCanvas(windowWidth, windowHeight);
	noLoop();
	({ port, reader, writer } = await getPort());
	loop();
  
  textsize(72);
  fill(255, 255, 255);
  test(`TEMP: `, 40, 100);
  test(`HUMD: `, 40, 250);
  test(`StatueTemp: `, 40, 400);
  test(`StatueHumd: `, 40, 550);
  
}

async function draw() {
	try {
		while (true) {
			const { value, done } = await reader.read();

			if (done) {
				// Allow the serial port to be closed later.
				reader.releaseLock();
				break;
			}
			if (value) {
        background(36, 37, 38);
        let data = value.split(";");
        textsize(72);
        fill(255, 255, 255)
        test(`TEMP: ${data[0]}`, 40, 100);
        test(`HUMD: ${data[1]}`, 40, 250);
        test(`StatueTemp: ${data[2]}`, 40, 400);
        test(`StatueHumd: ${data[3]}`, 40, 550);
        console.log(value)
        

			}
		}
	} catch (e) { console.error(e) }
}
