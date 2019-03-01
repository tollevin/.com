let str = ReasonReact.string;

type state = {
	menuOpen: bool,
};

type action =
| ToggleHamburger
| NavClick;

let reducer = (action, state) =>
	switch action {
	| ToggleHamburger => ReasonReact.Update({menuOpen: !state.menuOpen})
	| NavClick => ReasonReact.Update({menuOpen: false});
  };

let component = ReasonReact.reducerComponent("Nav");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {menuOpen: false},
  render: self => {
  	let menuOpen = self.state.menuOpen ? "menuOpen" : " ";
		let activeClass = self.state.menuOpen ? "open" : " ";
		let activePage = self.state.menuOpen ? "active" : " ";
  	<nav>
  		<div id="Logo">
  			<Link href="/" onClick=(_event => self.send(NavClick))>
  				<img src="/images/logo.png" alt="tollevin logo" />
  			</Link>
  		</div>
  		/*<Hamburger toggled=menuOpen onClick={self.handle(hamburgerClick)} />*/
  		<div id="Hamburger" onClick=(_event => self.send(ToggleHamburger)) className={activeClass}>
				<span></span>
				<span></span>
				<span></span>
			</div>
  		<div id="Nav-link-holder" className=menuOpen>
  			<div id="Alt-logo">
  				<Link href="/" onClick=(_event => self.send(NavClick))>
	  				<img src="/images/logo-white.png" alt="tollevin logo white" />
	  			</Link>
	  		</div>
	      <ul>
	        <li className={activePage}> <Link href="blog" onClick=(_event => self.send(NavClick))> (str("blog")) </Link> </li>
	        <li className={activePage}> <Link href="work" onClick=(_event => self.send(NavClick))> (str("work")) </Link> </li>
	        <li className={activePage}> <Link href="shop" onClick=(_event => self.send(NavClick))> (str("shop")) </Link> </li>
	        <li className={activePage}> <Link href="contact" onClick=(_event => self.send(NavClick))> (str("contact")) </Link> </li>
	      </ul>
	    </div>
    </nav>
  },
};