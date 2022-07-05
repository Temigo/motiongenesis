const Koa = require('koa');
const Router = require('@koa/router');
const cors = require('@koa/cors');
const serve = require('koa-static');
const path = require('path');
const koaBody = require('koa-body');

// Load CPP function using named export
const { String2String, String2Array, File2String } = require('./build/Release/hello_world_native.node');

// Create Koa app
const app = new Koa();

// Serve front-end statically
const buildPath = path.join(__dirname, '..', 'build');
app.use(serve(buildPath));
app.use(cors());
const router = new Router();

// Setup routes
router.get('/command/:text', (ctx) => {
    ctx.body = String2String(ctx.params.text);
});
router.get('/array/:text', (ctx) => {
    ctx.body = String2Array(ctx.params.text);
});
router.post('/upload', koaBody(), (ctx, next) => {
    // That contains a big string with the text file content
    // Lines are separated by \n
    let file_content = ctx.request.body.content;
    //console.log(file_content);
    //let lines = ctx.request.body.content.split('\n');
    //console.log(lines);
    //console.log(typeof(Buffer.from(lines)));
    const encoder = new TextEncoder();
    const uint8array = encoder.encode(file_content);
    console.log(uint8array);
    // TODO some more checks...
    ctx.status = 200;
    ctx.body = File2String(uint8array.buffer);
});

app
  .use(router.routes())
  .use(router.allowedMethods());

// Launch
const PORT = process.env.PORT || 3001;
app.listen(PORT);
