const Koa = require('koa');
const Router = require('@koa/router');
const cors = require('@koa/cors');
const serve = require('koa-static');
const path = require('path');

// Load CPP function using named export
const { String2String, String2Array } = require('./build/Release/hello_world_native.node');

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

app
  .use(router.routes())
  .use(router.allowedMethods());

// Launch
const PORT = process.env.PORT || 3001;
app.listen(PORT);
