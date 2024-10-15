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
![Bild4](https://github.com/user-attachments/assets/cad115db-9962-41c2-90dc-d85db8bda207)


# PMT Pulse-Stream Generator

The PMT Pulse-Stream Generator does not directly simulate a lifetime spectrum. Instead, it simulates PMT pulse pairs that contain the information necessary to determine the lifetime.

As shown in Figure 3, the different components of the spectrum can be identified:
![Bild3](https://github.com/user-attachments/assets/610ff18c-f4ff-4db8-9949-43803e0b9862)

1. **True Coincidence Events**  
   These events contain the actual lifetime information and make up the majority of a typical spectrum (around 80%). They represent real coincidences between detected events and are the main focus when analyzing the spectrum.

2. **Background Events**  
   Background events are uncorrelated events that occur due to the intensity of the source. These events are indistinguishable from true coincidence events and form the linear background of the spectrum.

3. **Pile Ups**  
   Pile ups occur when an additional pulse, caused by another decay, overlaps with a coincidence event. This leads to distorted time signals. The amount of pile ups is primarily influenced by the strength of the radioactive source being used.

4. **1275 keV Backscattering**  
   These events are caused by 1275 keV gamma quanta that undergo backscattering, interacting with both detectors. This can result in a false coincidence event that does not carry lifetime information.

5. **Bad Coincidence Events**  
   Bad coincidences occur when both collinear 511 keV gamma quanta, as well as the 1275 keV gamma, are detected. This leads to an amplitude shift of the 1275 keV gamma quantum in the PMT, resulting in a distorted time determination.
## License

[Add your preferred license here]

