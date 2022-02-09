import { createVuePlugin } from "vite-plugin-vue2"
import { defineConfig } from "vite"
const v = defineConfig({
    plugins: [createVuePlugin()],
    server: {
        port: 4500
    }
});
export default v;