PORTNAME=	libxdg-basedir
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	x11

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	Implementation of the XDG Base Directory specification

USES=		autoreconf gmake libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	davmac314
GNU_CONFIGURE=	yes
TEST_TARGET=	check

pre-configure:
	@${REINPLACE_CMD} -e 's|"etc"|"${PREFIX}/etc"|' \
		-e '/DefaultConfigDirectories\[\]/,/DefaultRelativeCacheHome\[\]/ s|"/\([^"]\)|"\1|' \
		-e '/DefaultConfigDirectories\[\]/,/DefaultRelativeCacheHome\[\]/ s|/|" DIR_SEPARATOR_STR "|g' \
		${WRKSRC}/src/basedir.c

.include <bsd.port.mk>
