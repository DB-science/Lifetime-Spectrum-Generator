# Lifetime Spectrum Generator

The **Lifetime Spectrum Generator** is a software tool designed to:

- Generate and save ideal lifetime spectra.
- Provide an advanced method for simulating complex spectra.

## Installation

1. Download the file `Lifetime Generator v1.0.exe`.
2. Run the installer to install the software.
3. After installation, open the software.

Upon opening the software, the following panel will appear:
![Bild1](https://github.com/user-attachments/assets/ef0123ed-388a-49e7-90af-b9fea0b5d2be)


## Usage

In the main panel, you can choose between:

- **Ideal Spectra Generator**: A basic tool for generating ideal spectra.
- **PMT Pulse Stream Generator**: A more complex simulation tool.

Click on the respective button to open the corresponding software.

### Ideal Spectra Generator

The **Ideal Spectra Generator** allows you to generate ideal spectra by entering the required parameters. It supports up to 5 components with different intensities (as shown in `Bild2.png`).
![Bild2](https://github.com/user-attachments/assets/8ff14411-d5a8-435f-abad-91507ca8008a)

#### Parameters:

- **Number of Components**: Select the number of components in the spectrum.
- **Spectrum Range (ns)**: Set the x-axis range in nanoseconds.
- **Binning (ps)**: Choose the binning for the histogram in picoseconds.
- **Number of Counts**: Set the total count in the resulting spectrum.
- **IRF (Instrument Response Function)**: You can define up to two Gaussian functions with arbitrary widths. One of the functions can be time-shifted.
- **BG (Background)**: Set the background count percentage. 1 corresponds to 100%.
- **Continuous Lifetime**: By enabling this checkbox, continuous lifetimes are used instead of discrete ones. The selected lifetimes represent the mean of the lifetime distributions, and their width is determined by the sigma value (in ns).

### Generating and Saving Spectra

After setting your desired parameters, click "Start" to generate the spectrum. You can then save the generated spectrum as a `.txt` file by clicking the "Save" button.

## License

[Add your preferred license here]

