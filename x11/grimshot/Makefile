PORTNAME=	grimshot
DISTVERSION=	1.8
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	344ab1a510c0.patch:-p2 # https://github.com/swaywm/sway/pull/5914

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Screenshot helper for Sway
WWW=		https://swaywm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC:H}/LICENSE

RUN_DEPENDS=	jq:textproc/jq \
		grim:x11/grim \
		slurp:x11/slurp

USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
GH_PROJECT=	sway
WRKSRC_SUBDIR=	contrib
NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	CLIPBOARD MANPAGES NOTIFY
OPTIONS_DEFAULT=CLIPBOARD MANPAGES NOTIFY

CLIPBOARD_DESC=		Copy to clipboard support
CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

do-build:
do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

.include <bsd.port.mk>
