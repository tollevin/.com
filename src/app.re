[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type route =
  | Home
  | Blog
  | Post
  | Work
  | Project
  | Shop
  | Contact
  | Follow;

type state = {route};

type action =
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) => {
  switch url.path {
  | [] => Home
  | ["/"] => Home
  | ["blog"] => Blog
  /*| ["blog", id] => handlePost(id)*/
  | ["work"] => Work
  | ["shop"] => Shop
  | ["contact"] => Home
  | _ => Home /*FIX Create 404*/
  };
};

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: mapUrlToRoute(ReasonReact.Router.dangerouslyGetInitialUrl())},
  didMount: self => {
    /*Js.log(self.state.route);*/
    let watcherID = ReasonReact.Router.watchUrl(url => {
      self.send(ChangeRoute(url |> mapUrlToRoute))
    });
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: (self) =>
    <div id="App">
      <Nav />
      <div className="container">
        (
          switch self.state.route {
          | Home => <Home />
          | Blog => <Blog />
          /*| Post => <Post id=id/>*/
          | Work => <Work />
          /*| Project => <Project />*/
          | Shop => <Shop />
          | Contact => <Home />
          /*| Follow => <Follow />*/
          }
        )
      </div>
    </div>,
};
