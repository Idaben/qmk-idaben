// Animation parameters
#define FRAME_DURATION 200 // How long each frame lasts in milliseconds

// Animation variables
uint32_t timer = 0;
uint8_t current_frame = 0;
int anim_sel = 1;

// Render animation
static void render_animation(int x) {

    anim_sel = x;

    #include "anim_byte_array.c"

    const char* epd_bitmap_allArray [] = {
        run_0,
        run_1
    };

    //const char* epd_bitmap_frame_0_delay_0 = run_0;
    //const char* epd_bitmap_frame_1_delay_0 = run_1;

    // Animation frames array
    switch (anim_sel) {
        case 0:
            epd_bitmap_allArray[0] = run_0;
            epd_bitmap_allArray[1] = run_1;
            break;

        case 1:
            epd_bitmap_allArray[0] = walk_0;
            epd_bitmap_allArray[1] = walk_1;
            break;
        case 2:
            epd_bitmap_allArray[0] = bark_0;
            epd_bitmap_allArray[1] = bark_1;
            break;
        case 3:
            epd_bitmap_allArray[0] = sneak_0;
            epd_bitmap_allArray[1] = sneak_1;
            break;
        case 4:
            epd_bitmap_allArray[0] = sit_0;
            epd_bitmap_allArray[1] = sit_1;
            break;

        default:
            epd_bitmap_allArray[0] = sit_0;
            epd_bitmap_allArray[1] = sit_1;
            break;
    }

    // Frame sizes array
    uint16_t frame_sizes[2] = {
        //this is fixed since we use the same thing
        sizeof(run_0),
        sizeof(run_1)
    };


    // Run animation
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated time
        timer = timer_read();

        // Increment frame
        current_frame = (current_frame + 1) % (sizeof(epd_bitmap_allArray) / sizeof(epd_bitmap_allArray[0]));

        // Draw frame to OLED
        oled_write_raw_P(epd_bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
}