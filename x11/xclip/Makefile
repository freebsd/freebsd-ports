# Created by: ijliao
# $FreeBSD$

PORTNAME=	xclip
PORTVERSION=	0.13
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface to X selections ("the clipboard") from the command line

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	astrand

USES=		autoreconf gmake iconv xorg
USE_XORG=	x11 xmu

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_X11_Xmu_Atoms_h=yes \
		ac_cv_header_X11_Intrinsic_h=yes \
		ac_cv_lib_Xmu_XmuClientWindow=yes

PLIST_FILES=	bin/xclip bin/xclip-copyfile bin/xclip-cutfile \
		bin/xclip-pastefile \
		man/man1/xclip.1.gz man/man1/xclip-copyfile.1.gz

post-patch:
	${REINPLACE_CMD} 's,mktemp,mktemp -t xclip,' ${WRKSRC}/xclip-copyfile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xclip

.include <bsd.port.mk>
