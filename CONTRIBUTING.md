# Contributing to Sorting Techniques Visualiser

## How to Contribute

### Adding a New Algorithm

1. Create a new file in `src/algorithms/YourAlgorithm.h`
2. Implement the sorting logic using the Visualizer callbacks
3. Use `viz->compare()`, `viz->swap()`, and `viz->mark()` callbacks
4. Register in the UI control
5. Update documentation

### Reporting Issues

- Use GitHub Issues with clear descriptions
- Include steps to reproduce
- Provide screenshots if applicable
- Include system information (OS, compiler version)

### Submitting Pull Requests

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/your-feature`)
3. Commit changes (`git commit -am 'Add your feature'`)
4. Push to branch (`git push origin feature/your-feature`)
5. Submit a Pull Request with clear description

## Coding Standards

- Use C++17 standard
- Follow naming conventions (CamelCase for classes, camelCase for variables)
- Add comments for complex logic
- Test your changes before submitting
- Keep functions small and focused

## Areas for Contribution

- [ ] Additional sorting algorithms (Timsort, Introsort, etc.)
- [ ] Graphics library integration (SDL2, SFML)
- [ ] Sound effects for operations
- [ ] Export as video/GIF
- [ ] Mobile responsive web version
- [ ] Custom comparison function support
- [ ] Algorithm difficulty ratings
- [ ] Interview question integration
- [ ] Performance benchmarking tools
- [ ] Documentation improvements

## Code Review Process

All PRs will be reviewed for:
- Code quality and style
- Algorithm correctness
- Performance implications
- Documentation completeness
- Test coverage

Thank you for contributing!
