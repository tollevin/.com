type state = {
	active: bool,
};

type action =
  | Toggle;

let reducer = (action, state) =>
	switch action {
	| Toggle => ReasonReact.Update({active: !state.active})
  };

let component = ReasonReact.reducerComponent("Hamburger");

let make = (~onClick, _children) => {
	...component,
  reducer,
  initialState: () => {active: false},
  render: self => {
  	let className = self.state.active ? "open" : " ";
  	<div id="Hamburger" onClick=(_event => self.send(Toggle)) className={className}>
			<span></span>
			<span></span>
			<span></span>
		</div>
	},
};
