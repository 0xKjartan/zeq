#include <sokol_gfx.h>
#include <sokol_app.h>
#include <sokol_glue.h>

sg_pass_action pass_action;

void init(void) {
    sg_setup(&(sg_desc){
        .environment = sglue_environment(),
    });
    pass_action = (sg_pass_action) {
        .colors[0] = {
            .load_action = SG_LOADACTION_CLEAR,
            .clear_value = { 0.0f, 0.0f, 0.0f, 1.0f }
        }
    };
}

void frame(void) {
    sg_begin_pass(&(sg_pass){ .action = pass_action, .swapchain = sglue_swapchain() });
    sg_end_pass();
    sg_commit();
}

void cleanup(void) {
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .width = 800,
        .height = 600,
        .window_title = "zeq",
        .icon.sokol_default = true,
    };
}
