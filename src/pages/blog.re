type post = {
	title: string,
	description: string,
	content: string,
	author: string,
	category: list(string),
	enclosure: string,
	pubDate: string,
	source: string,
};

type state = {
	posts: list(post)
};

let component = ReasonReact.reducerComponent("Blog");

let make = (_children) => {
	...component,
	reducer: ((), _) => ReasonReact.NoUpdate,
	initialState: () => {
		posts: [
			/*{
				title: string,
				description: string,
				content: string,
				author: string,
				category: array(string),
				enclosure: string,
				pubDate: string,
				source: string,
			},*/
			{
				title: "Watashi no Mission wa...",
				description: "Welcome to my digital home... it's an imperfect analogy.",
				content: "<p>Welcome to my digital 'home'. It's an imperfect analogy. This isn't where much of my digital life will take place. Here is where I will decoratively arrange the husks of personally meaningful events, much like a mantle. It's where I hope friends and family and even strangers will pop in for tea. <span className='pullquote'>Here is where you'll find me.</span></p>

				<p>The purpose of this site, beyond being my digital, public face in the Levinasian sense, is to experiment with and demonstrate what it means to be a individuated digital entity today. Living online always was cyber-serfdom, and the chains with which it binds have become noticably heavier lately. Many people, including myself, have begun to cut ties with the gatekeepers that once seemed necessary to be connected digitally. But cutting each tie comes with it's own new difficulties, deficiencies, and in most cases requires an alternative. In these posts, I'll be navigating the paths I take on the journey to digital autonomy, and recording them. Along the way, there will certainly be diversions, projects that catch my eye, experiences and opinions to share, etc.. I endeavor to record whatever seems of value.</p>

				<p>This is actually my first, and hopefully my last, 'Hello World' post. But more than that, it is a statement of intent. Taking inspiration from the great and timely Kondo-Sama, my mission is to take something as quotidien as being online, and make it a philosophical practice. May all digital beings find liberation.</p>",
				author: "tollevin",
				category: ["hello world", "digital", "cyborg", "autonomy"], 
				enclosure: "/images/kondo-sama.png",
				pubDate: "Fri Feb 15 2019",
				source: "tollevin.com"
			}
		]
	},
	render: ({state: {posts}}) =>
		<div id="Blog" className="page">
			<h1 className="page-title">(ReasonReact.string("blog"))</h1>
			<div className="post-previews">
				(
					ReasonReact.array(Array.of_list(
            List.map((post) => <PostPreview enclosure=post.enclosure title=post.title description=post.description content=post.content pubDate=post.pubDate />, posts)
          ))
        )
      </div>
		</div>,
}