open Canvas;

/*Setup Images*/
[@bs.module] external splashImg : string = "../images/splash.png";

/*Setup Extra Calls*/
external refToCanvas : Dom.element => Canvas.canvasElement = "%identity";
external refToImg : Dom.element => Document.element = "%identity";
external canvToElement : Canvas.canvasElement => Document.element = "%identity";

/*Types*/
type state = {
	ctx: ref(option(Canvas.ctx)),
	img: ref(option(Document.element)),
	mouseXY: list(int),
};

/*Global vars*/
let windowWidth = Document.getWindowWidth;
let splashAspect = 0.7518796992481203;

/*Actions.noStateChange*/
let refToContext = canv =>
  switch (Js.Nullable.toOption(canv)) {
  | Some(canv) => Some(Canvas.getContext(refToCanvas(canv)))
  | None => None
  };

let refToImg = imgr =>
  switch (Js.Nullable.toOption(imgr)) {
  | Some(imgr) => Some(refToImg(imgr))
  | None => None
  };

let draw = (ctx, img, mouseXY) => {
	let canvasHeight = Math.minInt(int_of_float(float_of_int(windowWidth) *. splashAspect), 1200);
	let canvasWidth = Math.minInt(windowWidth, 1596);
	let imgWidth = Document.naturalWidth(img);
	let imgHeight = Document.naturalHeight(img);

	let mouseX = ref(List.nth(mouseXY, 0));
	let mouseY = ref(List.nth(mouseXY, 1));

	let scale = (value, low1, high1, low2, high2) => {
	  low2 +. (high2 -. low2) *. (value -. low1) /. (high1 -. low1);
	}

	let mouseXFactor = ref(scale(float_of_int(mouseX^), 0., float_of_int(canvasWidth), 0.05, 1.));
	let mouseYFactor = ref(scale(float_of_int(mouseY^), 0., float_of_int(canvasHeight), 0.05, 1.));

	let tileWidth = float_of_int(canvasWidth) /. float_of_int(imgWidth);
	let tileHeight = float_of_int(canvasHeight) /. float_of_int(imgHeight);
	Ctx.drawImage(ctx, img, 0, 0);
	let imgData = Ctx.getImageData(ctx, 0, 0, imgWidth, imgHeight);
	Ctx.clearRect(ctx, 0., 0., float_of_int(canvasWidth), float_of_int(canvasHeight));

	for (gridX in 0 to (imgWidth - 1)) {
    for (gridY in 0 to imgHeight) {      
    	let posX = int_of_float(tileWidth *. float_of_int(gridX));
			let posY = int_of_float(tileHeight *. float_of_int(gridY));
      /*get current color*/
      let rgbC = Ctx.getColorForCoord(imgData, gridX, gridY, imgWidth);
      let rgbR = rgbC[0];
      let rgbG = rgbC[1];
      let rgbB = rgbC[2];
      let cRgbString = "rgb(" ++ string_of_int(rgbR) ++ ", " ++ string_of_int(rgbG) ++ 
        ", " ++ string_of_int(rgbB) ++ ")";
      /*greyscale conversion*/
      let greyscale = Math.round(float_of_int(rgbR) *. 0.222 +. float_of_int(rgbG) *. 0.707 +. float_of_int(rgbB) *. 0.071);
      /* case 3 */
      /* greyscale to line length */
      /*let l3 = scale(float_of_int(greyscale), 0., 255., 30., 0.1);
      let l4 = l3 +. mouseXFactor^;
		  Ctx.setStrokeStyle(ctx, "Black");
		  Ctx.setLineWidth(ctx, 10. *. mouseYFactor^);
      Ctx.beginPath(ctx);
      Ctx.line(ctx, (float_of_int(posX), float_of_int(posY)), (float_of_int(posX) +. l4, float_of_int(posY) +. l4));*/
      /* case 5 */
      /*greyscale to line relief*/
      /*let w5 = scale(float_of_int(greyscale), 0., 255., 5., 0.2);
      Ctx.setLineWidth(ctx, w5 *. mouseYFactor^ +. 0.1);
      /* get neighbour pixel, limit it to image width */
      let c2 = Ctx.getColorForCoord(imgData, int_of_float(Math.min([|float_of_int(gridX + 1), float_of_int(imgWidth - 1)|])), gridY, imgWidth);
      let rgbC2 = Ctx.getColorForCoord(imgData, gridX, gridY, imgWidth);
      let rgbR2 = rgbC2[0];
      let rgbG2 = rgbC2[1];
      let rgbB2 = rgbC2[2];
      let cRgbString2 = "rgb(" ++ string_of_int(rgbR2) ++ ", " ++ string_of_int(rgbG2) ++ 
        ", " ++ string_of_int(rgbB2) ++ ")";
		  Ctx.setStrokeStyle(ctx, cRgbString2);
      let greyscale2 = Math.round(float_of_int(rgbR2) *. 0.222 +. float_of_int(rgbG2) *. 0.707 +. float_of_int(rgbB2) *. 0.071);
      let h5 = 50. *. mouseXFactor^;
      let d1 = scale(float_of_int(greyscale), 0., 255., h5, 0.);
      let d2 = scale(float_of_int(greyscale2), 0., 255., h5, 0.);
      Ctx.line(ctx, (float_of_int(posX) -. d1, float_of_int(posY) +. d1), (float_of_int(posX) +. tileWidth -. d2, float_of_int(posY) +. d2));*/
      /* case 6 */
      /*pixel color to fill, greyscale to ellipse size*/
      let w6 = scale(float_of_int(greyscale), 0., 255., 25., 0.);
      Ctx.setFillStyle(ctx, cRgbString);
    	Ctx.beginPath(ctx);
      Ctx.ellipse(ctx, float_of_int(posX), float_of_int(posY), w6 *. mouseXFactor^, w6 *. mouseXFactor^, 0., 0., 2. *. Math.pi);
		  Ctx.fill(ctx);
		  /* case 7 */
		  /*Ctx.setStrokeStyle(ctx, cRgbString);
      let w7 = scale(float_of_int(greyscale), 0., 255., 5., 0.1);
      Ctx.setLineWidth(ctx, w7);
      /*fill(255, 255 * mouseXFactor^);*/
      /*Js.log(mouseXFactor^);*/
      Ctx.save(ctx);
      Ctx.translate(ctx, posX, posY);
      Ctx.rotate(ctx, float_of_int(greyscale) /. 255. *. Math.pi *. mouseYFactor^);
      Ctx.beginPath(ctx);
      Ctx.strokeRect(ctx, 0., 0., 15., 15.);
      Ctx.restore(ctx);*/
    }
  }
}

/*Actions.stateChange*/
let setCtxRef = (r, {ReasonReact.state}) => {
	state.ctx := refToContext(r);
}

let setImgRef = (r, {ReasonReact.state}) => {
	state.img := refToImg(r);
}

/*let setPointer = (evt, {ReasonReact.state}) => {
	state.mouseX := Document.getClientX(evt);
}*/

type action =
  | SetPointer(Document.mouseEvent);

/*let reducer = (action, _state) =>
  switch (action) {
  | SetPointer(event) => {
  	state.mouseX := Document.getClientX(event);
  	/*state.mouseY := Document.getClientX(event);*/
  };*/

/*Component*/
let component = ReasonReact.reducerComponent("Home");

/*Make*/
let make = (_children) => {
	...component,
	initialState: () => {
		ctx: ref(None),
		img: ref(None),
		mouseXY: [0,0]
	},
	/*reducer: ((), _) => ReasonReact.NoUpdate,*/
	reducer: (action, state) => {
		switch (action) {
		| SetPointer(evt) => ReasonReact.Update({...state, mouseXY: [ Document.getClientX(evt), Document.getClientY(evt) ]})
		}
	},
	/*didUpdate: ({oldSelf, newSelf}) => {*/
	didMount: ({state} as self) => {
		switch (state.img^) {
    | Some(img) => {
	    	switch (state.ctx^) {
		    	| Some(ctx) => {
		    		Document.set_onload(img, [@bs.this] ((o, v) => draw(ctx, img, state.mouseXY)));
		    		listen_to_canvas(
					    Ctx.canvas(ctx),
					    ((x, y)) => {
					      draw(ctx, img, [int_of_float(x),int_of_float(y)]);
					    },
					  );
		    	}
		    	| None => ()
		    }
	    }
    | None => ()
    };
  },
	render: self =>
		<div id="Home" className="page">
			<div id="Lander">
				<canvas
						width=(string_of_int(windowWidth))
						height=(string_of_int(int_of_float(float_of_int(windowWidth) *. splashAspect)))
            id="Splash"
            ref=(self.handle(setCtxRef))
          />
        <img id="SplashImg" ref=(self.handle(setImgRef)) src=splashImg alt="Me on the beach"/>
        <h2 className="holla">(ReasonReact.string("holla"))</h2>
			</div>
			/*<div className="content">
				<div><h1>(ReasonReact.string("Blah blah blah"))</h1></div>
			</div>*/
		</div>,
};