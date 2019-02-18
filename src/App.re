// import App.css 
[%bs.raw {|require('./App.css')|}];
// import logo.svg
[@bs.module] external logo : string = "./logo.svg";

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
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> {ReasonReact.string(message)} </h2>
      </div>
      <div className="App-intro"> <TodoTask /> </div>
    </div>,
};