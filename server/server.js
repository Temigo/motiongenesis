const Koa = require('koa');
const Router = require('@koa/router');
const cors = require('@koa/cors');

// Load CPP function using named export
const { HelloWorld } = require('./build/Release/hello_world_native.node');

// Create Koa app
const app = new Koa();
app.use(cors());
const router = new Router();

// Setup routes
router.get('/', (ctx) => {
    ctx.body = 'Hello World, welcome to the backend';
});

router.get('/command/:text', (ctx) => {
    ctx.body = HelloWorld(ctx.params.text);
});

app
  .use(router.routes())
  .use(router.allowedMethods());

// Launch
const PORT = process.env.PORT || 3001;
app.listen(PORT);
