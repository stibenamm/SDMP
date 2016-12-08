document.addEventListener("DOMContentLoaded", function(event) {
        var g1, g2;

        var g1 = new JustGage({
            id: "g1",
            value: getRandomInt(0, 100),
            min: 0,
            max: 100,
            relativeGaugeSize: true,
            pointer: true,
            pointerOptions: {
              toplength: -15,
              bottomlength: 10,
              bottomwidth: 12,
              color: '#8e8e93',
              stroke: '#ffffff',
              stroke_width: 3,
              stroke_linecap: 'round'
            },
            counter: true
        });

        var g2 = new JustGage({
            id: "g2",
            value: getRandomInt(0, 100),
            min: 0,
            max: 100,
            relativeGaugeSize: true,
            pointer: true,
            pointerOptions: {
              toplength: -15,
              bottomlength: 10,
              bottomwidth: 12,
              color: '#8e8e93',
              stroke: '#ffffff',
              stroke_width: 3,
              stroke_linecap: 'round'
            },
            counter: true
        });

        
});


FusionCharts.ready(function(){
    var battery = new FusionCharts({
    type: 'vled',
    renderAt: 'battery-chart',
    width: '150',
    height: '220',
    dataFormat: 'json',
    dataSource: {
        "chart": {
            "caption": "",
            "lowerLimit": "100",
            "upperLimit": "150",
            "numberSuffix": "V",
            "showTickMarks": "0",
            "showTickValues": "0",
            "valueFontSize": "0",
            "showhovereffect": "1",
            "ledSize": "18",
            "ledGap": "3",
            "manageResize": "1",
            "useSameFillColor": "1",
            "useSameFillBgColor": "1",
            "theme": "fint",
            "gaugeBorderAlpha":"100",
            "gaugeBorderThickness":"50",
            "gaugeBorderColor":"#666666"
        },
        //All annotations are grouped under this element
        "annotations": {
            "showbelow": "1",
            "groups": [{
                //Each group needs a unique ID
                "id": "indicator",
                "items": [

                    {
                        "id": "bgRectAngle",
                        //Polygon item
                        "type": "rectangle",
                        "alpha": "90",
                        "radius": "1",
                        "fillColor": "#6baa01",
                        "x": "$gaugeCenterX - 20",
                        "tox": "$gaugeCenterX + 20",
                        "y": "$gaugeEndY + 25",
                        "toy": "$gaugeEndY + 45"
                    }
                ]
            }]

        },
        "colorRange": {
            "color": [{
                "minValue": "100,0",
                "maxValue": "119,0",
                "code": "#e44a00"
            }, {
                "minValue": "120,0",
                "maxValue": "125,0",
                "code": "#f8bd19"
            }, {
                "minValue": "126,0",
                "maxValue": "144,0",
                "code": "#6baa01"
            }, {
                "minValue": "145,0",
                "maxValue": "150,0",
                "code": "#e44a00"
            }]
        },
        "value": "126"
    },
    "events": {
        "drawComplete": function(evt, arg) {
            var i,
                //Annotation
                annotations = evt.sender.annotations,
                //Value
                val = evt.sender.getData(),
                //Color Range Array
                crArr = evt.sender.args.dataSource.colorRange.color;

            for (i = crArr.length - 1; i >= 0; i--) {
                //When value falls within the color range
                if (val >= crArr[i].minValue && val <= crArr[i].maxValue) {
                    annotations.update('bgRectAngle', {
                        "fillColor": crArr[i].code
                    });
                }
            }

        }
    }

}
);



 var fuel = new FusionCharts({
    type: 'vled',
    renderAt: 'fuel-chart',
    width: '150',
    height: '220',
    dataFormat: 'json',
    dataSource: {
        "chart": {
            "caption": "",
            "lowerLimit": "0",
            "upperLimit": "100",
            "lowerLimitDisplay": "Empty",
            "upperLimitDisplay": "Full",
            "numberSuffix": "%",
             "showTickMarks": "1",
            "showTickValues": "1",
            "valueFontSize": "8",
            "showhovereffect": "1",
            "origW": "180",
            "origH": "250",
            "ledSize": "15",
            "ledGap": "0",
            "manageResize": "1",
            "useSameFillColor": "1",
            "useSameFillBgColor": "1",
            "theme": "fint",
            "gaugeBorderAlpha":"100",
            "gaugeBorderThickness":"100",
            "gaugeBorderColor":"#666666"
        },
        //All annotations are grouped under this element
        "annotations": {
            "showbelow": "1",
            "groups": [{
                //Each group needs a unique ID
                "id": "indicator",
                "items": [

                    {
                        "id": "bgRectAngle",
                        //Polygon item
                        "type": "rectangle",
                        "alpha": "90",
                        "radius": "1",
                        "fillColor": "#6baa01",
                        "x": "$gaugeCenterX - 20",
                        "tox": "$gaugeCenterX + 20",
                        "y": "$gaugeEndY + 25",
                        "toy": "$gaugeEndY + 45"
                    }
                ]
            }]

        },
        "colorRange": {
            "color": [{
                "minValue": "0",
                "maxValue": "100",
                "code": "#6baa01"
            }]
        },
        "value": "12"
    },
    "events": {
        "drawComplete": function(evt, arg) {
            var i,
                //Annotation
                annotations = evt.sender.annotations,
                //Value
                val = evt.sender.getData(),
                //Color Range Array
                crArr = evt.sender.args.dataSource.colorRange.color;

            for (i = crArr.length - 1; i >= 0; i--) {
                //When value falls within the color range
                if (val >= crArr[i].minValue && val <= crArr[i].maxValue) {
                    annotations.update('bgRectAngle', {
                        "fillColor": crArr[i].code
                    });
                }
            }

        }
    }

}
);

    fuel.render();
    battery.render();
});