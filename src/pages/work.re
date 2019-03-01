[@bs.module] external turingImg : string = "./turing.gif";
[@bs.module] external dm16 : string = "../images/destination_moon_16.jpg";


type project = {
  image: string,
  company: string,
  role: string,
  description: string,
  achievements: list(string),
  website: string,
  location: string,
  startDate: string,
  endDate: string,
  highlights: list(string)
};

type state = {
	projects: list(project)
};

let component = ReasonReact.reducerComponent("Work");

let make = (_children) => {
	...component,
	reducer: ((), _) => ReasonReact.NoUpdate,
	initialState: () => {
		projects: [
      {
        image: turingImg,
        company: "Turing",
        role: "Founder",
        description: "",
        achievements: ["full stack development"],
        website: "turing.nyc",
        location: "NY, NY",
        startDate: "Jan '19",
        endDate: "Present",
        highlights: [
          "full stack development",
          "reasonml",
          "react",
          "bucklescript",
          "concept design",
          "branding design",
          "creative direction",
          "canvas api",
          "printmaking"
        ]
      },
      {
        image: "https://s3-media3.fl.yelpcdn.com/bphoto/If-8qLOWcIAV4WWyUgSGoQ/o.jpg",
        company: "Fed",
        role: "Co-Founder+CXO",
        description: "",
        achievements: [
          "end-to-end development a complete user | product experience, from concept to branding design to UI to dining experience to post-use lifecycle design",
          "full stack development of MVP using Node|Meteor|Mongo",
          "project management of further webdev",
          "creative direction of all styles, assets and content",
          "integrated SEM and analytics with Google Analytics",
          "integrated payments with Stripe API",
        ],
        website: "getfednyc.com",
        location: "Brooklyn, NY",
        startDate: "Sept '16",
        endDate: "Dec '18",
        highlights: [
          "full stack development",
          "node",
          "meteor",
          "mongoDB",
          "user experience design",
          "project management",
          "marketing strategy",
          "creative direction",
          "food photography",
          "food styling",
          "packaging",
          "logistics"
        ]
      },
      {
        image: dm16,
        company: "Destination Moon",
        role: "Branding/Creative",
        description: "",
        achievements: [""],
        website: "destinationmoon.us",
        location: "Greater NY",
        startDate: "Apr '16",
        endDate: "Jun '16",
        highlights: [
          "oenology",
          "pos & ecommerce",
          "sales strategy"
        ]
      },
      {
        image: "http://myrtleavenue.org/wp-content/uploads/2014/10/Gnarly-Vines-shingle-blog-ready.jpg",
        company: "Gnarly Vines",
        role: "Project Manager",
        description: "",
        achievements: [""],
        website: "gnarlyvines.com",
        location: "Brooklyn, NY",
        startDate: "<START_DATE>",
        endDate: "<END_DATE>",
        highlights: [
          "oenology",
          "pos & ecommerce",
          "sales strategy"
        ]
      },
    ]
	},
	render: ({state: {projects}}) => 
		<div id="Work" className="page">
			<h1 className="page-title">(ReasonReact.string("work"))</h1>
			<div className="project-previews">
				(
					ReasonReact.array(Array.of_list(
            List.map((project) => <Project image=project.image company=project.company role=project.role description=project.description achievements=project.achievements website=project.website location=project.location startDate=project.startDate endDate=project.endDate highlights=project.highlights />, projects)
          ))
        )
      </div>
		</div>,
}