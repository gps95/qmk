# Compile
qmk compile -kb gps95/corne_choc_pro/mini -km default
# Flash
qmk flash -kb gps95/corne_choc_pro/mini -km default

If you change the info.json rgb_matrix values, you need to flash both halves sepparately.
If you bricked it, bootmagic is q and p, hold while connecting to enter boot mode.

# Default values for info.json stuff

## Default rgb_matrix
Needs config flags RGB_MATRIX_FRAMEBUFFER_EFFECTS and RGB_MATRIX_KEYPRESSES
"rgb_matrix": {
    "driver": "ws2812",
    "max_brightness": 100,
    "animations": {
        "alphas_mods": true,
        "gradient_up_down": true,
        "gradient_left_right": true,
        "breathing": true,
        "band_sat": true,
        "band_val": true,
        "band_pinwheel_sat": true,
        "band_pinwheel_val": true,
        "band_spiral_sat": true,
        "band_spiral_val": true,
        "cycle_all": true,
        "cycle_left_right": true,
        "cycle_up_down": true,
        "rainbow_moving_chevron": true,
        "cycle_out_in": true,
        "cycle_out_in_dual": true,
        "cycle_pinwheel": true,
        "cycle_spiral": true,
        "dual_beacon": true,
        "rainbow_beacon": true,
        "rainbow_pinwheels": true,
        "raindrops": true,
        "jellybean_raindrops": true,
        "hue_breathing": true,
        "hue_pendulum": true,
        "hue_wave": true,
        "pixel_fractal": true,
        "pixel_flow": true,
        "pixel_rain": true,
        "typing_heatmap": true,
        "digital_rain": true,
        "solid_reactive_simple": true,
        "solid_reactive": true,
        "solid_reactive_wide": true,
        "solid_reactive_multiwide": true,
        "solid_reactive_cross": true,
        "solid_reactive_multicross": true,
        "solid_reactive_nexus": true,
        "solid_reactive_multinexus": true,
        "splash": true,
        "multisplash": true,
        "solid_splash": true,
        "solid_multisplash": true
    }
}