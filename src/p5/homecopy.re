/*type sketch = {
	preload: unit => option(string),
	setup: unit => unit,
	draw: unit => unit
};*/
type state = {
	ctx: ref(option(Canvas.ctx)),
};

external refToCanvas : Dom.element => Canvas.canvasElement = "%identity";

let refToContext = canv =>
  switch (Js.Nullable.toOption(canv)) {
  | Some(canv) => Some(Canvas.getContext(refToCanvas(canv)))
  | None => None
  };

let setCtxRef = (r, {ReasonReact.state}) => state.ctx := refToContext(r);

type action =
  | Draw(Canvas.ctx);

let component = ReasonReact.reducerComponent("Home");

let make = (_children) => {
	...component,
	initialState: () => {
		ctx: ref(None),
		/*animation: option(ref(int))*/
	},
	reducer: (action, state) =>
		switch (action) {
		/*| DidMount(animation) => ReasonReact.Update({...state, animation})*/
		| Draw(ctx) => ReasonReact.Update({...state, ctx})
    /*| Click =>
      switch (state.ctx^) {
      | None => ReasonReact.NoUpdate
      | Some(ctx) =>
        ReasonReact.SideEffects(
          (
            self =>
              record(
                state.settings,
                ctx,
                self.reduce(blobUrl => SaveBlob(blobUrl)),
              )
          ),
        )
      }
    | SettingsUpdate(settings) => ReasonReact.Update({...state, settings})*/
	},
	/*didUpdate: ({oldSelf, newSelf}) => {*/
	didMount: ({state} as self) => {
		switch (state.ctx^) {
    | Some(ctx) => self.send(Draw(ctx))
    | None => ()
    };
  },
	render: self =>
		<div id="Home" className="page">
			<div id="Lander">
				<canvas
            width="600"
            height="600"
            className="canvas"
            ref=(self.handle(setCtxRef))
          />
			</div>
			<div className="content">
			</div>
		</div>,
};