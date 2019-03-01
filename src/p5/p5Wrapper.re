open P5;
open Sketch;

type state = {
  sketch: unit,
  node: ref(option(Dom.element))
};

/*[@bs.new][@bs.module ("../p5/p5.js","p5")] external p5 : unit => p5Inst = "";*/

let setNode = (theRef, {ReasonReact.state}) => {
  state.node := Js.Nullable.toOption(theRef);
};

let component = ReasonReact.reducerComponent("P5Wrapper");

let make = (_children) => {
  ...component,
  reducer: ((), _) => ReasonReact.NoUpdate,
  initialState: () => {
  	sketch: sketch(),
  	node: ref(None)
  },
  didMount: (self) => {
    let canvas = p5(sketch());

    /*ReactDOMRe.renderToElementWithId(canvas, "foo");*/
    /*self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));*/
  },
  render: (self) =>
    <div id="foo" ref={self.handle(setNode)}></div>,
};