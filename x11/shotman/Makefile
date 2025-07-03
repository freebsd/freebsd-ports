PORTNAME=	shotman
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.7
PORTREVISION=	9
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~whynothugo/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
# XXX Teach USES=cargo to not override default DISTFILES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Uncompromising screenshot GUI for Wayland
WWW=		https://sr.ht/~whynothugo/shotman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE.md

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cargo pkgconfig
CARGO_ENV=	SHOTMAN_VERSION="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}_completions \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	. ${PORTNAME}_completions

OPTIONS_DEFINE=	MANPAGES SLURP
OPTIONS_DEFAULT=MANPAGES SLURP

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

SLURP_DESC=		Interactive region selector
SLURP_RUN_DEPENDS=	slurp:x11/slurp

do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

post-install:
.for _shell in bash fish zsh
	@${ECHO_MSG} "Generating ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}"
	${CARGO_TARGET_DIR}/*/${PORTNAME}_completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
