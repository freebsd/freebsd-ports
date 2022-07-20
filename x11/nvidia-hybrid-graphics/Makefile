PORTNAME=	nvidia-hybrid-graphics
PORTVERSION=	0.5
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	theron.tarigo@gmail.com
COMMENT=	NVIDIA secondary GPU configuration - Optimus Technology support

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	nvidia-xconfig:x11/nvidia-xconfig \
		${LOCALBASE}/bin/Xorg:x11-servers/xorg-server

FLAVORS=	default 390

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/src

default_RUN_DEPENDS=	\
	nvidia-secondary-driver>=440.64:x11/nvidia-secondary-driver
390_RUN_DEPENDS=	\
	nvidia-secondary-driver-390>=390.87:x11/nvidia-secondary-driver-390

VIRTUALGL_RUN_DEPENDS=	${LOCALBASE}/VirtualGL/bin/vglrun:x11/virtualgl

390_PKGNAMESUFFIX=	-390

OPTIONS_DEFINE=		VIRTUALGL OPTIRUN
OPTIONS_DEFAULT=	VIRTUALGL OPTIRUN
OPTIONS_SUB=		OPTIRUN
VIRTUALGL_DESC=		Use VirtualGL for OpenGL redirection support
OPTIRUN_DESC=		Install "optirun" alias for nvrun-vgl
OPTIRUN_IMPLIES=	VIRTUALGL

scripts=	\
	bin/Xorg-nvidia-headless \
	bin/nvidia-headless-xconfig \
	bin/nvrun \
	bin/nvrun-vgl \
	libexec/nvidia-headless-utils/readconf \
	libexec/nvidia-settings-hybrid
configs=	\
	etc/X11/xorg-nvidia-headless-template.conf \
	etc/nvidia-headless.conf \
	etc/nvidia-hybrid.conf \

SUB_FILES=	pkg-message ${scripts:%=src/%} ${configs:%=src/%}
SUB_LIST+=	VGLRUN=${LOCALBASE}/VirtualGL/bin/vglrun

USE_RC_SUBR=	nvidia_xorg

do-extract:
.for f in ${SUB_FILES}
	${MKDIR} ${WRKDIR}/${f:H}
.endfor

do-install:
.for f in ${scripts}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${f:H}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for f in ${configs}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${f:H}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${f}.sample
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg-nvidia-headless.conf.d

post-install-OPTIRUN-on:
	@${RLN} ${STAGEDIR}${PREFIX}/bin/nvrun-vgl \
		${STAGEDIR}${PREFIX}/bin/optirun

.include <bsd.port.mk>
