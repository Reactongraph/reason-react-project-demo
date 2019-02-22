// import App.css
[%bs.raw {|require('../app.css')|}];
// define stateless component
let component = ReasonReact.statelessComponent("App");

/*
~ indicating that it was passed into the App component as a props and
the second parameter has _, this is a more explicit way of showing that the parameter isn’t used and ignored.

the …component spread operator indicated that the make function declared is building upon the component that was just defined. 
We also declare a render function with a single argument _self that is not used at the moment.
*/

//  ReasonReact.string(). is used to render string
let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="app">
      <div className="app-header">
        <div className="welcome-message-div">
          <h2 className="welcome-message"> {ReasonReact.string(message)}</h2>
        </div>
      </div>
      <div className="header-div">
       <p className="title"> {ReasonReact.string("ReasonReact add todo list app")} </p>
      </div>
      <div className="app-intro"> <TodoTask /> </div>
    </div>,
};