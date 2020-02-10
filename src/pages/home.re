open Canvas;

/*Setup Images*/
[@bs.module] external splashImg : string = "../images/splash.png";
[@bs.module] external turingCircle : string = "../images/turing-circle.png";
[@bs.module] external mapCircle : string = "../images/map-circle.png";
[@bs.module] external clapCircle : string = "../images/clap.png";

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
let windowHeight = Document.getWindowHeight;
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

	let mouseXFactor = ref(scale(float_of_int(canvasWidth - mouseX^), 0., float_of_int(canvasWidth), 0.05, 1.));
	let mouseYFactor = ref(scale(float_of_int(canvasHeight - mouseY^), 0., float_of_int(canvasHeight), 0.05, 1.));

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

      /*pixel color to fill, greyscale to ellipse size*/
      let w6 = scale(float_of_int(greyscale), 20., 300., 10., 0.);
      Ctx.setFillStyle(ctx, cRgbString);
    	Ctx.beginPath(ctx);
      Ctx.ellipse(ctx, float_of_int(posX), float_of_int(posY), w6 *. mouseXFactor^, w6 *. mouseXFactor^, 0., 0., 2. *. Math.pi *. mouseYFactor^);
		  Ctx.fill(ctx);
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
  // | UpdateCanvasSize(Document.getWindowWidth)

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
		mouseXY: [300,10]
	},
	reducer: (action, state) => {
		switch (action) {
		| SetPointer(evt) => ReasonReact.Update({...state, mouseXY: [ Document.getClientX(evt), Document.getClientY(evt) ]})
		}
	},
	didMount: ({state} as self) => {
		switch (state.img^) {
      | Some(img) => {
      	switch (state.ctx^) {
  	    	| Some(ctx) => {
  	    		Document.set_onload(img, [@bs.this] ((o, v) => draw(ctx, img, state.mouseXY)));
  	    		Document.listen_for_mouseEvt(
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
			</div>
      <div id="Hello">
        <p>(ReasonReact.string("Hi"))</p>
        <h1 className="intro">
          (ReasonReact.string("I'm Tollevin -"))
          <br/>
          (ReasonReact.string("a digital designer"))
          <br/>
          (ReasonReact.string("based in Brooklyn, NY."))
        </h1>
      </div>
      <div id="What">
        <div className="veil"></div>
        <div className="what-text">
          <p>
            (ReasonReact.string("I make products that promote a sustainable and equitable future."))
            <br/>
            (ReasonReact.string("And lots of tea."))
          </p>
          <p>
            (ReasonReact.string("My aim is to help illuminate and sublimate the systems that oppress us. My interests include tech, tech policy, complex systems, political economic theory, holistic sustainability, and baked goods."))
            // <span className="">
              // into "))<a href="https://solid.inrupt.com/about" >(ReasonReact.string("Solid"))</a>(ReasonReact.string(" and dApps."))
          </p>
        </div>
        <div className="antiveil"></div>
        <div className="pveil"></div>
        <div className="project-links">
          <h2>(ReasonReact.string("Projects"))</h2>
          <div className="links-holder">
            <a href="https://blacksocialists.us/clapback-chest" className="project-preview clapbacks">
              <div className="preview-text">
                <h3>(ReasonReact.string("BSA's Clapback Chest"))</h3>
                <p>(ReasonReact.string("A search engine for all things social and political"))</p>
              </div>
              <img src=clapCircle className="" />
            </a>
            <a href="https://blacksocialists.us/dual-power-map" className="project-preview dual-power-map">
              <div className="preview-text">
                <h3>(ReasonReact.string("The Dual Power Map"))</h3>
                <p>(ReasonReact.string("Find and support worker self-directed enterprises in the US."))</p>
              </div>
              <img src=mapCircle className="" />
            </a>
            <a href="/work#Turing" className="project-preview turing">
              <div className="preview-text">
                <h3>(ReasonReact.string("Turing.nyc"))</h3>
                <p>(ReasonReact.string("Digital design meets old-school fabrication."))</p>
              </div>
              <img src=turingCircle className="" />
            </a>
            <a href="/work" className="work-link">(ReasonReact.string("See more..."))</a>
          </div>
        </div>
        <div className="pantiveil"></div>
      </div>
      // <div id="CreativePreview">
      // </div>  
		</div>
};