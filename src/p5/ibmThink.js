/////////////////// HTML

<svg class="svg" width="540" height="565.71424" viewBox="0 0 580 800">
  <g class="isolate">
    <path class="blend t1"
    style="opacity:1;fill:#dd5d20;fill-opacity:1;fill-rule:evenodd;stroke:#dd5d20;stroke-width:79.81949615;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
    d="m 215.47816,252.84847 115.22634,0" />
    <path class="blend t2"
    d="m 273.09133,252.65768 0,115.22634"
    style="display:inline;opacity:1;fill:#dd5d20;fill-opacity:1;fill-rule:evenodd;stroke:#0b9444;stroke-width:79.81949615;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
    <circle class="t3"
  style="opacity:1;fill:#dd5d20;fill-opacity:1;stroke:none;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
  cx="273"
  cy="252.36218"
  r="40" />
    <path class="blend l1"
    style="display:inline;opacity:1;fill:#1f91ac;fill-opacity:1;fill-rule:evenodd;stroke:#1f91ac;stroke-width:79.81949615;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
    d="m 410.71374,252.65768 0,115.22634" />
    <path class="blend l2"
    d="m 410.47816,365.44844 114.22634,0"
    style="opacity:1;fill:#dd5d20;fill-opacity:1;fill-rule:evenodd;stroke:#df871b;stroke-width:79.81949615;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
    <circle class="l3"
  style="opacity:1;fill:#FFF;fill-opacity:1;stroke:none;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
  cx="411"
  cy="366.36218"
  r="40" />
    <path class="blend v1"
    d="m 272,562.64847 59.22634,-115"
    style="opacity:1;fill:#dd5d20;fill-opacity:1;fill-rule:evenodd;stroke:#dd5d20;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
    <path class="blend v3"
  style="display:inline;opacity:1;fill:#dd5d20;fill-opacity:1;fill-rule:evenodd;stroke:#1f91ac;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
    d="m 214.9,448.56614 59,115.22634" />
    <circle class="v2"
  r="40"
  cy="562.36218"
  cx="273"
  style="opacity:1;fill:#dd5d20;fill-opacity:1;stroke:none;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
    <path class="blend n1"
    d="m 410.71374,448.36614 0,115.22634"
    style="display:inline;opacity:1;fill:#1f91ac;fill-opacity:1;fill-rule:evenodd;stroke:#da3931;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
    <path class="blend n2"
    style="display:inline;opacity:1;fill:#1f91ac;fill-opacity:1;fill-rule:evenodd;stroke:#da3931;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
    d="m 526.004,448.36614 0,115.22634" />
    <path class="blend n3"
    style="fill:none;fill-rule:evenodd;stroke:#0b9444;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
    d="m 410.7,448.46218 115.37,115.013" />
  </g>
  <circle class="n4"
  style="opacity:1;fill:#da3931;fill-opacity:1;stroke:none;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1"
  cx="410.70001"
  cy="448.66217"
  r="40" />
  <circle class="n5"
  r="40"
  cy="563.16217"
  cx="526"
  style="opacity:1;fill:#da3931;fill-opacity:1;stroke:none;stroke-width:80;stroke-linecap:round;stroke-linejoin:miter;stroke-miterlimit:4;stroke-opacity:1" />
</svg>


/////////////////// CSS

body {
  background-color: #E8E6DA;
}

.svg {
  display: block;
  margin: 0 auto;
  margin-top: -20px;
}
.blend {
  mix-blend-mode: multiply;
}
.isolate {
  isolation: isolate;
}


/////////////////// JS

var timeline = anime.timeline({ autoplay: true, direction: 'alternate', loop: true });

function setDash(el) {
  if (el.nodeName === 'path') {
    el.style.dashArray = anime.setDashoffset(el);
    return [anime.setDashoffset(el) - 1, 0];
  }
  
  return 0;
}

var animations = [
  { name: '.t1', x: 195.47816, y: 152.84847, stroke: '#dd5d20' },
  { name: '.t2', x: 254.09133, y: 152.65768, stroke: '#0b9444' },
  { name: '.t3', x: 254.09133, y: 152.65768, fill: '#da3931' },
  { name: '.l1', x: 387.71374, y: 152.65768, stroke: '#1f91ac' },
  { name: '.l2', x: 387.71374, y: 265.44844, stroke: '#df871b' },
  { name: '.l3', x: 387.71374, y: 265.44844, fill: '#df871b' },
  { name: '.v1', x: 258.09133, y: -152.65768, stroke: '#dd5d20' },
  { name: '.v2', x: 251, y: 465, fill: '#ffffff' },
  { name: '.v3', x: -7, y: 450, stroke: '#1f91ac' },
  { name: '.n1', x: 387.71374, y: 348.36614, stroke: '#da3931' },
  { name: '.n2', x: 499.004, y: 348.36614, stroke: '#da3931' },
  { name: '.n3', x: 395.7, y: 348.46218, stroke: '#0b9444' },
  { name: '.n4', x: 387.70001, y: 450, fill: '#da3931' },
  { name: '.n5', x: 600.70001, y: 563.16217, fill: '#da3931' },
];

animations.forEach(function(animation, index) {
  if (animation.stroke) {
    timeline
    .add({
      targets: animation.name,
      stroke: {
        value: ['#000', animation.stroke],
        duration: 500,
        delay: 1000 + index * 30,
        easing: 'easeInOutQuad'
      },
      offset: 0
    });
  }
  if (animation.fill) {
    timeline
    .add({
      targets: animation.name,
      fill: {
        value: ['#000', animation.fill],
        duration: 500,
        delay: 1000 + index * 30,
        easing: 'easeInOutQuad'
      },
      offset: 0
    });
  }
  timeline
  .add({
    targets: animation.name,
    translateX: {
      value: [100 * (index % 4) - animation.x + 100, -100],
      duration: 500,
      delay: 1000 + index * 30,
      easing: 'easeInOutQuad'
    },
    translateY: {
      value: [100 * Math.floor(index / 4) - animation.y + 100, -100],
      duration: 500,
      delay: 1000 + index * 30,
      easing: 'easeInOutQuad'
    },
    offset: 0
  });
  timeline
  .add({
    targets: animation.name,
    strokeDashoffset: {
      value: setDash,
      duration: 800,
      delay: 1200 + index * 30,
      easing: 'easeInOutQuad'
    },
    offset: 0
  });
});

timeline
.add({
  targets: '.t1',
  opacity: 1,
  duration: 1000,
  delay: 4000,
  offset: 0
});