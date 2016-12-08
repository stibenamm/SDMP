<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <title>Dashboard</title>

        <link href="{!! asset('css/bootstrap.css') !!}" media="all" rel="stylesheet" type="text/css" />
        <link href="{!! asset('css/custom.css') !!}" media="all" rel="stylesheet" type="text/css" />

    </head>
    <body>
        <div class="flex-center position-ref full-height">
            @if (Route::has('login'))
                <div class="top-right links">
                    <a href="{{ url('/login') }}">Login</a>
                    <a href="{{ url('/register') }}">Register</a>
                </div>
            @endif

            <div class="jumbotron">
              <div class="container">
               
              </div>
            </div>

            <div class="container ">
                <div class="row">
                    <div class="col-md-5 well">
                        <div class="col-md-6" id="icon1">
                            <img class="img-responsive" src="img/icon1.png"  alt="">
                        </div>
                        <div class="col-md-6" id="g1" class="gauge"></div>
                    </div>
                    <div class="col-md-5 col-md-offset-2 well">
                        <div class="col-md-6" id="icon2">
                            <img class="img-responsive" src="img/icon2.png"  alt="">
                        </div>
                        <div class="col-md-6" id="g2" class="gauge"></div>
                    </div>
                </div>

                <div class="row">
                    <div class="col-md-5 well">
                        <div class="col-md-6 " id="icon3">
                            <img class="img-responsive" src="img/icon3.png"  alt="">
                        </div>
                        <div class="col-md-6" id="battery-chart"></div>
                    </div>
                    <div class="col-md-5 col-md-offset-2 well">
                        <div class="col-md-6 " id="icon4">
                            <img class="img-responsive" src="img/icon4.png"  alt="">
                        </div>
                        <div class="col-md-6" id="fuel-chart"></div>
                    </div>
                </div>
                


            </div>
        </div>
    <script type="text/javascript" src="{!! asset('js/jquery.min.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/bootstrap.min.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/raphael-2.1.4.min.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/justgage.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/fusioncharts.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/themes/fusioncharts.theme.fint.js') !!}"></script>
    <script type="text/javascript" src="{!! asset('js/charts.js') !!}"></script>

    </body>
</html>
