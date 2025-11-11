PORTNAME=	wleave
DISTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Wayland-native logout script written in GTK4
WWW=		https://github.com/AMNatty/wleave

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell

USES=		cargo gnome

USE_GITHUB=	yes
GH_ACCOUNT=	AMNatty

USE_GNOME=	cairo gtk40 libadwaita libxml2

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/icons/hibernate.svg \
		${DATADIR}/icons/lock.svg \
		${DATADIR}/icons/logout.svg \
		${DATADIR}/icons/reboot.svg \
		${DATADIR}/icons/shutdown.svg \
		${DATADIR}/icons/suspend.svg
PORTDOCS=	README.md

OPTIONS_DEFINE=	COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=COMPLETIONS MANPAGES

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/wleave.1.gz \
			share/man/man5/wleave.5.gz \
			share/man/man5/wleave.json.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/man/wleave.1.scd \
		${WRKSRC}/src/config.rs
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/layout.json \
		${WRKSRC}/man/wleave.json.5.scd

post-build-MANPAGES-on:
.for man in ${MANPAGES_PLIST_FILES:T:S/.gz//}
	scdoc < ${WRKSRC}/man/${man}.scd > ${WRKSRC}/man/${man}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.svg ${STAGEDIR}${DATADIR}/icons

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
.for man in ${MANPAGES_PLIST_FILES}
	${INSTALL_MAN} ${WRKSRC}/man/${man:T:S/.gz//} ${STAGEDIR}${PREFIX}/${man:H}
.endfor

.include <bsd.port.mk>
