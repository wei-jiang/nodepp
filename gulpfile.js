//npm install --save-dev gulp-concat gulp-minify-html gulp-minify-css gulp-uglify gulp-rename
var gulp = require('gulp')
    ,browserify = require('browserify')
    ,source = require('vinyl-source-stream')
    ,buffer = require('vinyl-buffer')
    ,fs = require("fs")
    ,minifyHtml = require("gulp-minify-html")
    ,gp_concat = require('gulp-concat')
    ,gp_rename = require('gulp-rename')
    ,gp_uglify = require('gulp-uglify')
    ,minifyCss = require("gulp-minify-css")
    ,del = require('del')
    ,babel = require('gulp-babel')
    ,es2015 = require('babel-preset-es2015')
    ,execSync = require('child_process').execSync
    ;
// task
gulp.task('clear', function () {
  return del([
    './dist/*'
  ]);
  //execSync("rm -rf " + "www");
});

gulp.task('build_cpp', function () {
    execSync('swig -c++ -javascript -node -DV8_VERSION=0x040685 .\\cxx\\cpp_back.i');
    execSync('nw-gyp rebuild --target=0.14.7 --msvs_version=2015 --arch=ia32 -C .\\cxx --python=C:\\Python27\\python.exe');   
});
gulp.task('build_sp', function () {
    execSync('node-pre-gyp rebuild --runtime=node-webkit --target=0.14.7 --msvs_version=2015 --arch=ia32 -C .\\svr\\node_modules\\serialport --python=C:\\Python27\\python.exe');   
});
gulp.task('cp_front', function () {
    gulp.src([
        './front/**/*'
    ]
    , { base: './front' })
    .pipe(gulp.dest('./dist/public'));
});
// gulp.task('build_spa', function () {
//     execSync('cd spa && npm run build');
// });
gulp.task('minify-html', function () {
    return gulp.src(['../public/*.html', '../main.html'], { base: '..' } ) 
    .pipe(minifyHtml())
    .pipe(gulp.dest('../dist/ssm'));
});

gulp.task('minify-js', function(){
    return gulp.src([
        '../public/app/*.js'        
        ]
        , { base: '..' } )
        .pipe(babel({
			presets: [es2015]
		}))
        .pipe(gp_uglify().on('error', function(e){
            console.log(e);
        }) )
        .pipe(gulp.dest('../dist/ssm'))
});
gulp.task('minify-node', function(){
    return gulp.src([
        ,'../dealers/*.js'
        ,'../*.js'
        // ,"!../node_modules{,/**}"
        ]
        , { base: '..' } )
        .pipe(babel({
			presets: [es2015]
		}))
        .pipe(gp_uglify().on('error', function(e){
            console.log(e);
        }) )
        .pipe(gulp.dest('../dist/ssm'))
});
gulp.task('minify-css', function () {
    return gulp.src(['../public/css/*.css', '../public/app/index.css'], { base: '..' } )
    .pipe(minifyCss())
    .pipe(gulp.dest('../dist/ssm'));
});
gulp.task('copy-res', ['cp_front'], function () {
    gulp.src([
        './deps/**/*'
    ]
    , { base: './deps' })
    .pipe(gulp.dest('./dist'));

    gulp.src([  
        "d:/tools/nwjs-sdk-v0.14.7-win-ia32/**/*"
    ]
    , { base: 'd:/tools/nwjs-sdk-v0.14.7-win-ia32' })
    .pipe(gulp.dest('./dist'));

    gulp.src([  
        './cxx/build/Release/cpp_back.node'
    ]
    , { base: './cxx' })
    .pipe(gulp.dest('./dist'));

    gulp.src([ './svr/**/*' ], { base: './svr' }).pipe(gulp.dest('./dist'));
});

gulp.task('release', [
    // 'minify-html'
    // , 'minify-js'
    // , 'minify-node'
    // , 'minify-css'
    'build_cpp'
    ,'copy-res'
    ], 
    function() {

    }
);
gulp.task('default', ['release'], function() {
  console.log("all done");
});