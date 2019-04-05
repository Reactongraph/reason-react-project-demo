// defines states
type state = {
  email: string,
  password: string,
};

// defines actions
type action =
  | InputEmailText(string)
  | InputPasswordText(string)
  | Submit

// defines Statefull component names Todo
let component = ReasonReact.reducerComponent("SignIn");
let loginDataKey = "loginDataKey"
let make = _children => {

  // Validate User
  let validateUser = (storedData, enteredData) =>
    if (storedData.email == enteredData.email &&
          storedData.password == enteredData.password) {
      true;
    } else {
      false;
    };

  // Added new item in list
  let handleSubmit = state => {
    let parseLoginData = [%bs.raw {| JSON.parse(localStorage.getItem("loginDataKey")) |}];
    let isValidated = validateUser(parseLoginData, state)
    if(isValidated) {
      ReasonReact.Router.push("dashboard");
    } else {
      [%bs.raw {| alert("Enter valid email and password") |}];
    }
    ReasonReact.Update({email: state.email, password: state.password});
  };

  let handleNavigation = () => {
    ReasonReact.Router.push("/");
  };

  // defines initial state
  {
    ...component,
    initialState: () => {
      email: "",
      password: ""
    },

    reducer: action =>
      switch (action) {
      // update state of input field
      | InputEmailText(email) => (
          state => ReasonReact.Update({...state, email})
        )
      | InputPasswordText(password) => (
          state => ReasonReact.Update({...state, password})
        )
      // Submit an items
      | Submit => (state => handleSubmit(state))
      },


    render: self => {
      let { email, password } = self.state;
      <div className="loginForm">
        <InputForm
          onSubmit={_ => self.send(Submit)}
          email
          password
          onEmailInputText={email => self.send(InputEmailText(email))}
          onPasswordInputText={password => self.send(InputPasswordText(password))}
          buttonText="Login"
          onNavigation={handleNavigation}
          navigationButtonText="SignUp"
          registrationTitle="Havn't signUp?"
        />
      </div>
    },
  };
};