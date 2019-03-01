let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
	...component,
	render: self => <div></div>,
}