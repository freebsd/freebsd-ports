PORTNAME=	uh-wm
PORTVERSION=	0.2.1
CATEGORIES=	x11-wm rubygems
MASTER_SITES=	RG

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Minimalistic tiling and stacking window manager

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-baf>=0.14.0:devel/rubygem-baf \
		rubygem-uh>=2.1.0:x11-toolkits/rubygem-uh \
		rubygem-uh-layout>=0.4.2:x11-wm/rubygem-uh-layout \
		rubygem-rb-kqueue>=0.2.4:devel/rubygem-rb-kqueue

USE_RUBY=	yes
USES=		gem
NO_ARCH=	yes

PLIST_FILES=	bin/uhwm

.include <bsd.port.mk>
