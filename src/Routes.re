let str = ReasonReact.string;

module type Config = {
  type route;
  let toUrl: route => string;
  let toRoute: ReasonReact.Router.url => route;
};

module CreateRouter = (Config: Config) => {
  type route = Config.route;

  // defines renderProps
  type renderProps = {
    updateRoute: route => unit,
    route,
  };

  // define state type
  type state = {route};

  // define action type
  type action =
    | UpdateRoute(route);

  let component = ReasonReact.reducerComponent("Router");
  let make = (~render, _children) => {
    ...component,
    initialState: () => {
      route: ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.toRoute,
    },
    subscriptions: self => [
      Sub(
        () =>
          ReasonReact.Router.watchUrl(url =>
            self.send(UpdateRoute(Config.toRoute(url)))
          ),
        ReasonReact.Router.unwatchUrl,
      ),
    ],
    reducer: (action, _state) =>
      switch (action) {
      | UpdateRoute(route) => ReasonReact.Update({route: route})
      },
    render: self =>
      render({
        updateRoute: route => self.send(UpdateRoute(route)),
        route: self.state.route,
      }),
  };
};

// defines routes name
type page =
  | Dashboard
  | SignIn
  | SignUp;

module Config = {
  type route = page;
  let toRoute = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | ["signin"] => SignIn
    | ["dashboard"] => Dashboard
    | _ => SignUp
    };
  let toUrl = route =>
    switch (route) {
    | SignIn => "/signin"
    | Dashboard => "/dashboard"
    | SignUp => "/"
    };
};

module Router = CreateRouter(Config);

  let component = ReasonReact.statelessComponent("Routes");
  let make = _self => {
    ...component,
    render: _self =>
      <div className="menuBar">
        <div className="menuItems">
          <Link route=SignUp toUrl=Config.toUrl render={() => str("SignUp")} />
          <Link
            route=SignIn
            toUrl=Config.toUrl
            render={() => str("SignIn")}
          />
          <Link
            route=Dashboard
            toUrl=Config.toUrl
            render={() => str("Dashboard")}
          />
        </div>
        <Router
          render={({route}) =>
            switch (route) {
            | Dashboard => <App message="Reason React Todo application" />
            | SignIn => <SignIn />
            | SignUp => <SignUp />
            }
          }
        />
      </div>,
  };
