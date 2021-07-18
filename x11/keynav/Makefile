PORTNAME=	keynav
PORTVERSION=	0.20180821.0	# to match the output of `keynav -v'
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	karlo@klarinet.osamsb.hr
COMMENT=	Quickly select a portion of the screen using minimal keystrokes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libxdo.so:x11/xdotool

USES=		gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jordansissel
GH_TAGNAME=	78f9e07
USE_GNOME=	cairo glib20
USE_XORG=	x11 xext xinerama xrandr

PLIST_FILES=	bin/keynav
PORTDOCS=	CHANGELIST README.md TODO
PORTEXAMPLES=	keynavrc keynavrc.jordan test.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${MV} ${WRKSRC}/examples/keynavrc.jordan ${WRKSRC}
# default RELEASE="$(date +%Y%m%d)", should not depend on the build date
	@${PRINTF} "MAJOR=0\nRELEASE=%s\nREVISION=0\n" \
		${PORTVERSION:S/./ /g:[2]} > ${WRKSRC}/VERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynav ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
