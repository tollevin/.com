open P5;

type drawMode =
	| One
	| Two
	| Three
	| Four
	| Five
	| Six
	| Seven
	| Eight
	| Nine;

let sketch = () => {
	p5();

	let mouseXFactor = ref(0);
	let mouseYFactor = ref(0);

	let width = 603;
	let height = 873;
	let drawMode = Seven;
	let img = loadImage("images/splash.png");
	let tileWidth = width / img.width;
	let tileHeight = height / img.height;

	let setup = () => {
	  let canvas = createCanvas(width, height);
	  /*print([%raw {|preloadedImg.width + " • " + preloadedImg.height|}]);*/
	  /*canvas.parent('Lander');
	  canvas.id('LanderCanvas');*/
	}

	let myCustomRedrawAccordingToNewPropsHandler = (mouseX, mouseY) => {
		let mouseXFactor = map(mouseX, 0, width, 0.05, 1.);
		let mouseYFactor = map(mouseY, 0, height, 0.05, 1.);
	}

	let draw = () => {
		background(255);

	  for (gridX in 0 to img.width) {
	    for (gridY in 0 to img.height) {      
	    	let posX = tileWidth * gridX;
				let posY = tileHeight * gridY;
	      /*get current color*/
	      loadPixels(img);
	      let c = color(get(img, gridX, gridY));
	      /*greyscale conversion*/
	      let greyscale = round(float_of_int(red(c)) *. 0.222 +. float_of_int(green(c)) *. 0.707 +. float_of_int(blue(c)) *. 0.071);

	      switch (drawMode) {
	      | One => {
	        /*greyscale to stroke weight*/
	        let w1 = map(greyscale, 0, 255, 15., 0.1);
	        stroke(0);
	        strokeWeight(int_of_float(w1) * mouseXFactor^);
	        line(posX, posY, posX + 5, posY + 5);
		      };
	      | Two => {
	        /*greyscale to ellipse area*/
	        fill(0);
	        noStroke();
	        let r2 = 1.1284 *. sqrt(float_of_int(tileWidth * tileWidth * (1 - greyscale / 255)));
	        let r3 = int_of_float(r2) * mouseXFactor^ * 3;
	        ellipse(posX, posY, r3, r3);
		      }
	      | Three => {
	        /*greyscale to line length*/
	        let l3 = map(greyscale, 0, 255, 30., 0.1);
	        let l4 = l3 *. float_of_int(mouseXFactor^);
	        stroke(0);
	        strokeWeight(10 * mouseYFactor^);
	        line(posX, posY, posX + int_of_float(l4), posY + int_of_float(l4));
		      }
	      | Four => {
	        /*greyscale to rotation, line length and stroke weight*/
	        stroke(0);
	        let w4 = map(greyscale, 0, 255, 10., 0.);
	        strokeWeight(int_of_float(w4 *. float_of_int(mouseXFactor^) +. 0.1));
	        let l4 = map(greyscale, 0, 255, 35., 0.);
	        let l5 = int_of_float(l4) * mouseYFactor^;
	        push();
	        translate(posX, posY);
	        rotate(float_of_int(greyscale / 255) *. pi);
	        line(0, 0, 0 + l5, 0 + l5);
	        pop();
		      }
	      | Five => {
	        /*greyscale to line relief*/
	        let w5 = map(greyscale, 0, 255, 5., 0.2);
	        strokeWeight(int_of_float(w5 *. float_of_int(mouseYFactor^) +. 0.1));
	        /*get neighbour pixel, limit it to image width*/
	        let c2 = color(get(img, min(gridX + 1, img.width - 1), gridY));
	        strokeWithP5Color(c2);
	        let greyscale2 = floor(float_of_int(red(c2)) *. 0.222 +. float_of_int(green(c2)) *. 0.707 +. float_of_int(blue(c2)) *. 0.071);
	        let h5 = 50 * mouseXFactor^;
	        let d1 = int_of_float(map(greyscale, 0, 255, float_of_int(h5), 0.));
	        let d2 = int_of_float(map(greyscale2, 0, 255, float_of_int(h5), 0.));
	        line(posX - d1, posY + d1, posX + tileWidth - d2, posY + d2);
		      }
	      | Six => {
	        /*pixel color to fill, greyscale to ellipse size*/
	        let w6 = map(greyscale, 0, 255, 25., 0.);
	        noStroke();
	        fillWithP5Color(c);
	        ellipse(posX, posY, int_of_float(w6 *. float_of_int(mouseXFactor^)), int_of_float(w6 *. float_of_int(mouseXFactor^)));
		      }
	      | Seven => {
	        strokeWithP5Color(c);
	        let w7 = map(greyscale, 0, 255, 5., 0.1);
	        strokeWeight(int_of_float(w7));
	        fillWithTuple(255, 255 * mouseXFactor^);
	        push();
	        translate(posX, posY);
	        rotate(float_of_int(greyscale / 255) *. pi *. float_of_int(mouseYFactor^));
	        rect(0, 0, 15., 15.);
	        pop();
		      }
	      | Eight => {
	        noStroke();
	        fillWithTriple(greyscale, greyscale * mouseXFactor^, 255 * mouseYFactor^);
	        rect(posX, posY, 3.5, 3.5);
	        rect(posX + 4, posY, 3.5, 3.5);
	        rect(posX, posY + 4, 3.5, 3.5);
	        rect(posX + 4, posY + 4, 3.5, 3.5);
		      }
	      | Nine => {
	        strokeWithRGB(255, greyscale, 0);
	        noFill();
	        push();
	        translate(posX, posY);
	        rotate(float_of_int(greyscale / 255) *. pi);
	        strokeWeight(1);
	        rect(0, 0, float_of_int(15 * mouseXFactor^), float_of_int(15 * mouseYFactor^));
	        let w9 = map(greyscale, 0, 255, 15., 0.1);
	        strokeWeight(int_of_float(w9));
	        strokeWithTuple(0, 70);
	        ellipse(0, 0, 10, 5);
	        pop();
		      }
	      };
	    }
	  }
	};
};
/*

function keyReleased() {
  if (key == 's' || key == 'S') saveCanvas(gd.timestamp(), 'png');

  // change draw mode
  if (key == '1') drawMode = 1;
  if (key == '2') drawMode = 2;
  if (key == '3') drawMode = 3;
  if (key == '4') drawMode = 4;
  if (key == '5') drawMode = 5;
  if (key == '6') drawMode = 6;
  if (key == '7') drawMode = 7;
  if (key == '8') drawMode = 8;
  if (key == '9') drawMode = 9;
}
};*/