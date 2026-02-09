// Scope CSS to this skin
document.documentElement.setAttribute('data-hashir-skin', '1');

const emoji = [
  "1️⃣",
  "2️⃣",
  "3️⃣",
  "4️⃣",
  "5️⃣",
  "6️⃣",
  "7️⃣",
  "8️⃣",
  "9️⃣"
];

const relabel = () => {
  document.querySelectorAll('.markdown ol').forEach((ol) => {
    ol.querySelectorAll('li').forEach((li, i) => {
      li.style.listStyleType = 'none';
      li.style.position = 'relative';
      li.style.paddingLeft = '1.5em';
      li.style.setProperty('--gpt-li', `"${emoji[i % emoji.length]} "`);
    });
  });
};

const markerCSS = `
  .markdown ol > li::marker { content: ""; }
  .markdown ol > li::before {
    content: var(--gpt-li, "• ");
    position: absolute;
    left: 0;
    top: 0;
  }
`;

const boot = () => {
  if (!document.head || !document.body) {
    requestAnimationFrame(boot);
    return;
  }

  if (!document.querySelector('#hashir-marker-style')) {
    const style = document.createElement('style');
    style.id = 'hashir-marker-style';
    style.textContent = markerCSS;
    document.head.appendChild(style);
  }

  relabel();
  new MutationObserver(relabel).observe(document.body, { subtree: true, childList: true });
};

boot();
