/*  required a stylesheet with [%bs.raw {|require('./index.css')|}]; at the top of the file. 
    BuckleScript allows us to include some raw JavaScript code by using
    [%bs.raw ] and wrapping the JavaScript code with {| |}.*/

[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  // import component App
  <App message="Reason React Todo application" />,
  "root",
);

register_service_worker();
