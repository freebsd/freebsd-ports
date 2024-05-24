PORTNAME=	Mowitz
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/mowitz/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Mowitz ("More widgets") library
WWW=		https://siag.nu/mowitz/

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USES=		libtool xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xawm=Xaw3d
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCS_MAKE_ENV=	PORTDOCS=yes

.include <bsd.port.mk>
